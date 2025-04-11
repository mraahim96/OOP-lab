#include <iostream>
using namespace std;

class Complex {
protected:
    double img, real;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        img = i;
    }

    Complex operator+(Complex& other) {
        return Complex(real + other.real, img + other.img);
    }

    Complex operator-(Complex& other) {
        return Complex(real - other.real, img - other.img);
    }

    Complex operator*(Complex& other) {
        return Complex(real * other.real - img * other.img, real * other.img + img * other.real);
    }

    Complex operator/(Complex& other) {
        double denominator = other.real * other.real + other.img * other.img;
        if (denominator == 0)
            throw "Division by zero error!";
        return Complex(
            (real * other.real + img * other.img) / denominator,
            (img * other.real - real * other.img) / denominator
        );
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.real;
        if (c.img >= 0)
            out << "+" << c.img << "i)";
        else
            out << "-" << -c.img << "i)";
        return out;
    }

    friend double magnitude(const Complex& c);

private:
    static double sqrt_manual(double value) {
        if (value == 0.0) return 0.0;
        double guess = value / 2.0;
        for (int i = 0; i < 10; ++i) {
            guess = (guess + value / guess) / 2.0;
        }
        return guess;
    }
};

double magnitude(const Complex& c) {
    double squareSum = c.real * c.real + c.img * c.img;
    return Complex::sqrt_manual(squareSum);
}

int main() {
    Complex c1(2, 3);
    Complex c2(1, -5);

    cout << "Complex Number 1: " << c1 << endl;
    cout << "Complex Number 2: " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "Sum: " << sum << endl;

    Complex diff = c1 - c2;
    cout << "Difference: " << diff << endl;

    Complex prod = c1 * c2;
    cout << "Product: " << prod << endl;

    Complex quot = c1 / c2;
    cout << "Quotient: " << quot << endl;

    cout << "Magnitude of Complex Number 1: " << magnitude(c1) << endl;
    cout << "Magnitude of Complex Number 2: " << magnitude(c2) << endl;

    return 0;
}
