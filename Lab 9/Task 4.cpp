#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading temperature data\n";
    }

    void displayReport() override {
        cout << "Temperature: 18 C\n";
    }
};

class Barometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading pressure data\n";
    }

    void displayReport() override {
        cout << "Pressure: 2014 hPa\n";
    }
};

int main() {
    WeatherSensor* s1 = new Thermometer();
    WeatherSensor* s2 = new Barometer();

    s1->readData();
    s1->displayReport();
    cout << endl;

    s2->readData();
    s2->displayReport();

    delete s1;
    delete s2;

}
