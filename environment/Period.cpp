//
// Created by bartek on 26.03.19.
//

#include "Period.h"
#include <string>
#include <regex>
#include "boost/algorithm/string.hpp"

using namespace utils;
using boost::algorithm::to_lower_copy;

Period::Period(const std::string &strPeriod) {
    std::smatch match;
    if (regex_match(strPeriod, match, PERIOD_REGEX)) {
        value = static_cast<uint32_t>(std::stoi(match[1].str()));
        if (match[2].length() == 0) {
            unit = S;
        } else {
            const std::string &strUnit = to_lower_copy(match[2].str());
            unit = STR_TO_UNIT.at(strUnit);
        }
    }
}

uint32_t Period::getInMilliseconds() {
    switch(unit) {
        case S:
            return value * SECOND;
        case M:
            return value * MINUTE;
        case H:
            return value * HOUR;
    }
}
