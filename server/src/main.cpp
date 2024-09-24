#include <boost/asio.hpp>
#include <iostream>
#include <array>

using boost::asio::ip::udp;

class UDPServer {
public:
    UDPServer(boost::asio::io_context& io_context, short port)
        : socket_(io_context, udp::endpoint(udp::v4(), port)) {
        start_receive();
    }

private:
    void start_receive() {
        socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            [this](std::error_code ec, std::size_t bytes_recvd) {
                if (!ec && bytes_recvd > 0) {
                    handle_receive(bytes_recvd);
                } else {
                    start_receive();
                }
            });
    }

    void handle_receive(std::size_t length) {
        std::cout << "Received: " << std::string(recv_buffer_.data(), length) << std::endl;

        std::string response = "Message received!";
        socket_.async_send_to(
            boost::asio::buffer(response), remote_endpoint_,
            [this](std::error_code, std::size_t) {
                start_receive();
            });
    }
    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    std::array<char, 1024> recv_buffer_;
};

int main() {
    try {
        boost::asio::io_context io_context;
        UDPServer server(io_context, 8080);
        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
