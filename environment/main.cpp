#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "configuration.h"
#include "Period.h"
#include "boost/math/interpolators/barycentric_rational.hpp"
#include "utills.h"
#include "Event.h"

using namespace std;
using namespace configuration;

void prepareData(const vector <TemperaturePoint> &temperaturePoints, vector<float> &x, vector<float> &y);

void loopData(vector<float> &x, vector<float> &y);

int openPublishFile();

int main(int argc, char *argv[]) {

    int fd = openPublishFile();

    const Configuration &config = loadConfiguration<Configuration>("configuration/config.yml");
    cout << config << endl;
    utils::Period period(config.timeStep);
    utils::Period delay(config.timeDelay);

    const vector <TemperaturePoint> &temperaturePoints = config.temperatures;
    vector<float> x;
    vector<float> y;

    prepareData(temperaturePoints, x, y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    boost::math::barycentric_rational<float> b(x.data(), y.data(), x.size(), 2);

    uint32_t currentTime = 0;
    uint32_t msPeriod = period.getInMilliseconds();
    uint32_t msDelay = delay.getInMilliseconds();


    while (true) {
        float temperature = b(static_cast<float>(currentTime) / 1000);
        Time time(2, 30, 30);
        event::Event event(time, temperature);
        cout << event << endl;
        write(fd, event.toString().data(), event.toString().size());
        usleep(msDelay * 1000);
        currentTime = (currentTime + msPeriod) % 86400000;
    }
}

void prepareData(const vector <TemperaturePoint> &temperaturePoints, vector<float> &x, vector<float> &y) {
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

int openPublishFile() {
    int fd = open("/pps/environment", O_CREAT | O_WRONLY, S_IRWXU | S_IROTH);
    if (fd == -1) {
        cout << "Couldn't open publish file" << endl;
    }
    return fd;
}