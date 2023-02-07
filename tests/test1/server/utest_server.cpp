#include <fstream>

#include "mu_test.h"
#include "server_app.hpp"

BEGIN_TEST(test)
    using namespace smart_home;
    
    std::ifstream stream("config.txt");
    
    size_t numOfThreads = 3;
    std::ofstream log("log.txt");

    ServerApp serverApp{"127.0.0.1", 8080, stream, log, numOfThreads};
    
    serverApp.Run();

    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(test)
END_SUITE