#include <unistd.h>
#include <iostream>
#include "configuration.h"
#include "Period.h"
#include "boost/math/interpolators/barycentric_rational.hpp"
#include "utills.h"

using namespace std;
using namespace configuration;

void prepareData(const vector<TemperaturePoint> &temperaturePoints, vector<float> &x, vector<float> &y);
void loopData(vector<float> &x, vector<float> &y);

int main(int argc, char *argv[]) {

    const Configuration &config = loadConfiguration<Configuration>("configuration/config.yml");
    utils::Period period(config.timeStep);
    utils::Period delay(config.timeDelay);

    const vector<TemperaturePoint> &temperaturePoints = config.temperatures;
    vector<float> x;
    vector<float> y;

    prepareData(temperaturePoints, x, y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    boost::math::barycentric_rational<float> b(x.data(), y.data(), x.size());

    uint32_t currentTime = 0;
    uint32_t msPeriod = period.getInMilliseconds();
    uint32_t msDelay = delay.getInMilliseconds();


    while (true) {
        cout << b(static_cast<float>(currentTime) / 1000) << endl;
        usleep(msDelay * 1000);
        currentTime = (currentTime + msPeriod) % 86400000;
    }
}

void prepareData(const vector<TemperaturePoint> &temperaturePoints, vector<float> &x, vector<float> &y) {
    x.reserve(temperaturePoints.size() + 1);
    y.reserve(temperaturePoints.size() + 1);
    for (TemperaturePoint temperaturePoint: temperaturePoints) {
        x.push_back(static_cast<float>(temperaturePoint.time.getTimestamp()) / 1000);
        y.push_back(static_cast<float>(temperaturePoint.value));
    }
    loopData(x, y);
}

void loopData(vector<float> &x, vector<float> &y) {
    x.push_back(x.front() + 86400);
    y.push_back(y.front());
}