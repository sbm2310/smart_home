#ifndef SERVER_APP_HPP
#define SERVER_APP_HPP

#include <chrono> //system_clock
#include <string>
#include <vector>
#include <memory>

#include "tcp_selector.hpp"
#include "tcp_server_socket.hpp"
#include "tcp_acceptor.hpp"

namespace smart_home 
{
class ServerApp 
{
public:
    ServerApp(std::string const& a_ip, size_t a_port, std::ifstream& a_configStream, std::ostream& a_logStream, size_t a_numOfThreads);
    ServerApp(ServerApp const& a_other) = delete;
    ServerApp& operator=(ServerApp const& a_other) = delete;
    ~ServerApp() = default;

    void Run();

private:
    std::string m_ip;
    size_t m_port;
    std::ifstream& m_configStream;
    std::ostream& m_logStream;
    size_t m_numOfThreads;
};
}//smart_home

#endif /* SERVER_APP_HPP */