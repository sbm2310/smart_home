#include <fstream>
#include <thread>

#include "mu_test.h"

#include "sensor_interface.hpp"
#include "sensor_temperature.hpp"
#include "sensor_fire_detector.hpp"
#include "sensor_badge.hpp"
#include "protocol.hpp"

BEGIN_TEST(test)
    using namespace smart_home;

    Protocol protocol;
    TemperatureSensor tempSens{protocol, "[temp-1-a]", "127.0.0.1", 8080};

    std::thread t1{[&](){
        tempSens.Run();
        }};

    t1.join();

    sleep(3.5);

    std::ifstream stream("../server/log.txt");

    std::string sensor, controller;

    while(stream.is_open() && !stream.eof()) {
        stream >> controller;

        if(controller == "CONTROLLER_SPRINKLER_ON") {
            ASSERT_PASS();
            break;
        }
    }

    TRACE(controller);

END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(test)
END_SUITE