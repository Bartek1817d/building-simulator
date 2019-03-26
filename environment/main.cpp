#include <iostream>
#include "configuration.h"
#include <boost/math/interpolators/barycentric_rational.hpp>
#include "utills.h"

using namespace std;
using namespace configuration;

void prepareData(const vector<TemperaturePoint> &temperaturePoints, vector<float> &x, vector<float> &y);

int main(int argc, char *argv[]) {
    const Configuration &config = loadConfiguration<Configuration>("configuration/config.yml");

    const vector<TemperaturePoint> &temperaturePoints = config.temperatures;
    vector<float> x;
    vector<float> y;

    prepareData(temperaturePoints, x, y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    boost::math::barycentric_rational<float> b(x.data(), y.data(), x.size());
    Time t(1u, 30u, 0u);

    cout << "Temperature = " << b(t.getTimestamp()) << endl;

    return 0;
}

void prepareData(const vector<TemperaturePoint> &temperaturePoints, vector<float> &x, vector<float> &y) {
    x.reserve(temperaturePoints.size());
    y.reserve(temperaturePoints.size());
    for (TemperaturePoint temperaturePoint: temperaturePoints) {
        x.push_back(temperaturePoint.time.getTimestamp());
        y.push_back(static_cast<float>(temperaturePoint.value));
    }
}