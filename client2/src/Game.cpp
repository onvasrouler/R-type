/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game
*/

#include "Game.hpp"

Game::Game() : _socket(nullptr)
{
    gameIsRunning = false;
}

Game::~Game()
{
}

void Game::run(sf::RenderWindow &window, boost::asio::io_context &io_context, boost::asio::ip::basic_resolver_results<boost::asio::ip::udp> &endpoints)
{
    gameIsRunning = true;
    backgroundTexture.loadFromFile("chipset/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    _socket = std::make_unique<boost::asio::ip::udp::socket>(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 8081));
    std::cout << "Socket: " << _socket->local_endpoint().address().to_string() << ": " << _socket->local_endpoint().port() << std::endl;
    
    startRecieve();

    std::string message = "00\r\n";
    std::vector<char> binary_message(message.begin(), message.end());

    std::cout << "Send: ";
    for (auto &c : binary_message)
        std::cout << c;
    std::cout << " to: " << endpoints->endpoint().address().to_string() << ":" << endpoints->endpoint().port() << std::endl;

    _socket->send_to(boost::asio::buffer(binary_message), *endpoints.begin());

    while (gameIsRunning) {
        processEvents(window, endpoints);
        render(window);

        io_context.poll();
    }
    io_context.stop();
}

void Game::startRecieve()
{
    sender_endpoint_ = boost::asio::ip::udp::endpoint();

    _socket->async_receive_from(boost::asio::buffer(recv_buffer), sender_endpoint_, [this](boost::system::error_code ec, std::size_t bytes_recvd) {
        handle_receive(ec, bytes_recvd);
    });
}

std::vector<std::string> split(const std::string& str, char delimiter, std::vector<std::string> &tokens) {
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    if (!tokens.empty() && tokens.back().size() >= 2) {
        tokens.back().erase(tokens.back().size() - 2, 2);
    }
    return(tokens);
}

void Game::update(std::string message)
{
    try {
        std::vector<std::string> instruction;
        split(message, '/', instruction);
        
        if (instruction[0].compare("01") == 0) {
            objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), PLAYER);
            id = instruction[1];
        }
        if (instruction[0].compare("200") == 0) {
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), PLAYER);
        }
        if (instruction[0].compare("210") == 0) {
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), ENEMY);
        }
        if (instruction[0].compare("220") == 0) {
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), BULLET);
        }
        if (instruction[0].compare("203") == 0 || instruction[0].compare("213") == 0 || instruction[0].compare("222") == 0) {
            if (objects.find(instruction[1]) != objects.end()) {
                if(instruction[1].compare(id) == 0) {
                    gameIsRunning = false;
                }
                objects.erase(instruction[1]);
            }
        }
        if (instruction[0].compare("202") == 0 || instruction[0].compare("212") == 0 || instruction[0].compare("221") == 0) {
            if (objects.find(instruction[1]) != objects.end()) {
                objects[instruction[1]]->setPosition(std::stoi(instruction[2]), std::stoi(instruction[3]));
            } else {
                if (instruction[0].compare("202") == 0) {
                    objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), PLAYER);
                } else if (instruction[0].compare("212") == 0) {
                    objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), ENEMY);
                } else if (instruction[0].compare("212") == 0) {
                    objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[2]), std::stoi(instruction[3]), BULLET);
                }
            }
        }
    }
    catch (const std::invalid_argument& e) {
        std::cout << "non\n";
    }
}

void Game::handle_receive(const boost::system::error_code& error, std::size_t bytes_recvd)
{
    if (!error) {
        std::string message(recv_buffer.data(), bytes_recvd);

        std::cout << message << std::endl;
        
        update(message);

        startRecieve();
    } else {
            std::cerr << "Error on receive: " << error.message() << std::endl;
    }
}

void Game::render(sf::RenderWindow &window)
{
    window.clear();

    window.draw(backgroundSprite);

    for (std::map<std::string, std::shared_ptr<GameObject>>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        window.draw(it->second->Sprite);
    }

    window.display();
}

void Game::processEvents(sf::RenderWindow &window, boost::asio::ip::basic_resolver_results<boost::asio::ip::udp> &endpoints){
    sf::Event event;
    std::string message;
    bool action = false;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Up) {
                message = "1/up\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Down) {
                message = "1/down\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Left) {
                message = "1/left\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Right) {
                message = "1/right\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Space) {
                message = "1/shoot\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Escape)
                gameIsRunning = false;
        }
    }

    if (action) {
        std::vector<char> binary_message(message.begin(), message.end());
        _socket->send_to(boost::asio::buffer(binary_message), *endpoints.begin());
    }
}
