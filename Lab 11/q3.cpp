#include <iostream>
#include <exception>

using namespace std;

class TemperatureTooLowException : public exception {};

template <typename T>
T toFahrenheit(T celsiusTemp) {
    if (celsiusTemp < static_cast<T>(-273.15)) {
        throw TemperatureTooLowException();
    }
    return (celsiusTemp * static_cast<T>(9.0 / 5.0)) + static_cast<T>(32);
}

int main() {
    try {
        cout << "Converting -300°C to Fahrenheit..." << endl;
        double result = toFahrenheit(-300.0);
        cout << "Temperature in Fahrenheit: " << result << "°F" << endl;
    } catch (TemperatureTooLowException& e) {
        cout << "Conversion failed: input is below absolute zero!" << endl;
        cout << "Exception message: " << e.what() << endl;
    }

    return 0;
}
