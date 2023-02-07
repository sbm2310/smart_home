#ifndef AGENT_FIRE_DETECTOR_SENSOR_HPP
#define AGENT_FIRE_DETECTOR_SENSOR_HPP

#include <string>

#include "agent_base.hpp"
#include "location.hpp"
#include "event.hpp"

namespace smart_home
{

class FireDetectorSensorAgent : public AgentBase
{
public:
    FireDetectorSensorAgent(std::string const& a_id, Location const& a_location, std::string const& a_log, std::string const& a_config);
    Event Act(std::vector<std::string> const& a_data, iagent::EventPtr a_eventsPublisher) const override;
};  
    
} // namespace smart_home


#endif // AGENT_FIRE_DETECTOR_SENSOR_HPP