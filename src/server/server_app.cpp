#include "server_app.hpp"
#include "tcp_event_handler.hpp"

#include <iostream>
namespace smart_home 
{

ServerApp::ServerApp(std::string const& a_ip, size_t a_port, std::ifstream& a_configStream, std::ostream& a_logStream, size_t a_numOfThreads)
: m_ip(a_ip)
, m_port(a_port)
, m_configStream(a_configStream)
, m_logStream(a_logStream)
, m_numOfThreads(a_numOfThreads)
{
}

void ServerApp::Run()
{
    using namespace net;

    TCPServerSocket server{m_ip.c_str(), static_cast<int>(m_port)};
    std::unique_ptr<Handler> handler{new EventHandler{m_configStream, m_logStream, m_numOfThreads}};
    std::unique_ptr<Acceptor> acceptor{new DefaultAcceptor{}};
    Selector selector{server, handler, acceptor};
    
    selector.Run();
}

}//smart_home