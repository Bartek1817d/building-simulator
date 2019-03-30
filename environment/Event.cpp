//
// Created by bartek on 30.03.19.
//

#include "Event.h"
#include <string>

using namespace event;

Event::Event(configuration::Time &time, float_t temperature) : time(time), temperature(temperature) {}

std::string Event::toString() const {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "@environment\ntime::%s\ntemperature::%f", time.toString().data(), temperature);
    return std::string(buffer);
}

std::ostream &operator<<(std::ostream &ostream, Event &event) {
    return ostream << event.toString();
}
