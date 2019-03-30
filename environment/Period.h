//
// Created by bartek on 26.03.19.
//

#ifndef ENVIRONMENT_PERIOD_H
#define ENVIRONMENT_PERIOD_H

#include <string>
#include <regex>
#include <map>
#include "boost/assign.hpp"

namespace utils {

    using boost::assign::map_list_of;

    enum Unit {
        S, M, H
    };

    const static uint32_t SECOND =  1000u;
    const static uint32_t MINUTE =  60u * SECOND;
    const static uint32_t HOUR =    60u * MINUTE;

    const static std::regex PERIOD_REGEX("(\\d+)([sSmMhH]?)");
    const static std::map<std::string, Unit> STR_TO_UNIT = map_list_of("s", S)("m", M)("h", H);

    class Period {
        Unit unit;
        uint32_t value;
    public:
        Period(const std::string &strPeriod);
        uint32_t getInMilliseconds();
    };

}


#endif //ENVIRONMENT_PERIOD_H
