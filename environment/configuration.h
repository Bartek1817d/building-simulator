//
// Created by bartek on 25.03.19.
//

#ifndef ENVIRONMENT_CONFIGURATION_H
#define ENVIRONMENT_CONFIGURATION_H

#include <iostream>
#include <vector>
#include <cstdint>
#include "yaml-cpp/yaml.h"

namespace configuration {

    template <typename Config> Config loadConfiguration(const std::string& path);

    class Time {
        uint8_t hours, minutes, seconds;
    public:
        Time();

        Time(uint8_t hours, uint8_t minutes, uint8_t seconds);

        uint8_t getHours() const;

        void setHours(uint8_t hours);

        uint8_t getMinutes() const;

        void setMinutes(uint8_t minutes);

        uint8_t getSeconds() const;

        void setSeconds(uint8_t seconds);

        float getTimestamp() const;

        Time &operator=(const Time &time);

        friend std::ostream& operator<<(std::ostream &stream, const Time &time);
    };

    struct TemperaturePoint {
        Time time;
        float value;

        friend std::ostream &operator<<(std::ostream &stream, const TemperaturePoint &temperaturePoint);
    };

    struct Configuration {
        std::vector<TemperaturePoint> temperatures;

        friend std::ostream &operator<<(std::ostream &stream, const Configuration &configuration);
    };

    extern template Configuration loadConfiguration<Configuration>(const std::string& path);

}

namespace YAML {
    template<>
    struct convert<configuration::Configuration> {
        static bool decode(const Node &node, configuration::Configuration &rhs);
    };

    template<>
    struct convert<configuration::TemperaturePoint> {
        static bool decode(const Node &node, configuration::TemperaturePoint &rhs);
    };

    template<>
    struct convert<configuration::Time> {
        static bool decode(const Node &node, configuration::Time &rhs);
    };
}

#endif //ENVIRONMENT_CONFIGURATION_H
