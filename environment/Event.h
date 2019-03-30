//
// Created by bartek on 30.03.19.
//

#ifndef ENVIRONMENT_EVENT_H
#define ENVIRONMENT_EVENT_H

#include <string>
#include <iostream>
#include "configuration.h"

namespace event {

    struct Event {
        configuration::Time time;
        float_t temperature;

        Event(configuration::Time &time, float_t temperature);

        std::string toString() const;
    };

}

std::ostream &operator<<(std::ostream &ostream, event::Event &event);

#endif //ENVIRONMENT_EVENT_H
