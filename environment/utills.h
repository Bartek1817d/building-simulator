//
// Created by bartek on 25.03.19.
//

#ifndef ENVIRONMENT_UTILLS_H

#include <iostream>
#include <vector>

template<typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector <T> &vector) {
    if (vector.empty()) {
        return stream << "[]";
    }
    stream << "[";
    for (auto it = vector.begin(); it != vector.end(); ++it) {
        stream << *it;
        if (it != vector.end() - 1)
            stream << ", ";
    }
    return stream << "]";
}


#define ENVIRONMENT_UTILLS_H

#endif //ENVIRONMENT_UTILLS_H
