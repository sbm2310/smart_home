#ifndef EVENT_HPP
#define EVENT_HPP

#include <chrono> //system_clock
#include <string>
#include <vector>
#include <fstream>

#include "location.hpp"

namespace smart_home 
{
struct Event 
{
public:
    std::ostream& Print(std::ostream &a_out) const;

    std::string timestamp;
    std::string eType;
    Location location;
    std::vector<std::string> payload;
};
}//smart_home

#include "inl/event.hxx"

#endif /* EVENT_HPP */