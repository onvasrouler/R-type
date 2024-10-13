/*
** EPITECH PROJECT, 2024
** R-type
** File description:
** game
*/

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include <map>
#include <memory>
#include <string>
#include <array>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

class Game
{
public:
    Game();
    ~Game();

    void run(sf::RenderWindow &window, boost::asio::io_context &io_context, boost::asio::ip::basic_resolver_results<boost::asio::ip::udp> &endpoints);
    void processEvents(sf::RenderWindow &window, boost::asio::ip::basic_resolver_results<boost::asio::ip::udp> &endpoints);
    void update(std::string message);
    void render(sf::RenderWindow &window);
    void startRecieve();
    void handle_receive(const boost::system::error_code& error, std::size_t bytes_recvd);

private:
    std::map<std::string, std::shared_ptr<GameObject>> objects;
    std::unique_ptr<boost::asio::ip::udp::socket> _socket;
    bool gameIsRunning;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::array<char, 1024> recv_buffer;
    std::vector<std::string> messages;
    sf::Font font;
    std::vector<sf::Text> textMessages;
    std::string id;
    sf::Texture enemyTexture;
    sf::Texture playerTexture;
    sf::Texture bulletTexture;
};

