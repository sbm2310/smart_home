#include <fstream>
#include "server_app.hpp"

int main() 
{
    using namespace smart_home;
    

    std::ifstream stream("config.txt");
    
    size_t numOfThreads = 3;
    std::ofstream log("log.txt", std::ios::app);
    ServerApp serverApp{"127.0.0.1", 8080, stream, log, numOfThreads};
    serverApp.Run();

    return 0;
}