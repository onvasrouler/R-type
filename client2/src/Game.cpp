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
    startRecieve();

    std::string message = "00\r\n";
    std::vector<char> binary_message(message.begin(), message.end());
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

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void Game::update(std::string message)
{
    std::vector<std::string> instruction = split(message, '/');
    try {
        if (instruction[0] == "01") {
            if (instruction.size() == 7)
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), PLAYER);
        }
        if (instruction[0] == "200") {
            if (instruction.size() == 7)
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), PLAYER);
        }
        if (instruction[0] == "210") {
            if (instruction.size() == 7)
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[5]), std::stoi(instruction[6]), ENEMY);
        }
        if (instruction[0] == "220") {
            if (instruction.size() == 5)
                objects[instruction[1]] = std::make_shared<GameObject>(std::stoi(instruction[3]), std::stoi(instruction[4]), BULLET);
        }
        if (instruction[0] == "203" || instruction[0] == "213" || instruction[0] == "222") {
            if (instruction.size() == 2)
                objects.erase(instruction[1]);
        }
        if (instruction[0] == "202" || instruction[0] == "212" || instruction[0] == "221") {
            if (instruction.size() == 4)
                objects[instruction[1]]->setPosition(std::stoi(instruction[2]), std::stoi(instruction[3]));
        }
    }
    catch (const std::invalid_argument& e) {
        std::cout << "error"<< std::endl;
    }

}

void Game::handle_receive(const boost::system::error_code& error, std::size_t bytes_recvd)
{
    if (!error) {
        std::string message(recv_buffer.data(), bytes_recvd);

        std::cout << message << std::endl;
        size_t pos = message.find("Message received: ");
            if (pos != std::string::npos) {
                message.erase(pos, 18);
            }
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
                message = "1/space\r\n";
                action = true;
            } else if(event.key.code == sf::Keyboard::Num0)
                gameIsRunning = false;
        }
    }

    if (action) {
        std::vector<char> binary_message(message.begin(), message.end());
        _socket->send_to(boost::asio::buffer(binary_message), *endpoints.begin());
    }
}
