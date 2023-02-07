#ifndef EVENT_HXX
#define EVENT_HXX

#include <iomanip>

#include "event.hpp"

namespace smart_home 
{
inline std::ostream& Event::Print(std::ostream &a_out) const
{ 
    a_out << "Time: " << timestamp << '\n';
    a_out << "Event type: " << eType << '\n';
    a_out << "Floor: " << location.floor << '\n';
    a_out << "Room: " << location.room << '\n';
    a_out << "Payload: ";

    for(auto const& it: payload) {
        a_out << it << '\n';
    }
    
    a_out << std::endl << std::endl;

    return a_out;
}

}//smart_home

#endif /* EVENT_HXX */