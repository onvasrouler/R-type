#include <boost/asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::udp;

int main() {
    try {
        boost::asio::io_context io_context;

        udp::socket socket(io_context);
        socket.open(udp::v4());

        udp::resolver resolver(io_context);
        udp::resolver::results_type endpoints = resolver.resolve(udp::v4(), "127.0.0.1", "8080");

        std::string message = "Hello from client!";
        socket.send_to(boost::asio::buffer(message), *endpoints.begin());

        std::array<char, 1024> recv_buffer;
        udp::endpoint sender_endpoint;
        size_t len = socket.receive_from(boost::asio::buffer(recv_buffer), sender_endpoint);

        std::cout << "Reply from server: " << std::string(recv_buffer.data(), len) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
