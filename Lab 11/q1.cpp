#include<iostream>
#include<sstream>
#include<exception>
using namespace std;

class MismatchException : public exception {
private:
    string message;
public:
    MismatchException(int r1, int c1, int r2, int c2) {
        ostringstream oss;
        oss << "MismatchException: " << r1 << "x" << c1 << " + " << r2 << "x" << c2;
        message = oss.str();
    }

    const char* what() const noexcept override{
        return message.c_str();
    }
};

template<typename T>
class Matrix {
private:
    T** data;
    int rows, colms;

public:
    Matrix(int r, int c) : rows(r), colms(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[colms];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        cout << "Enter elements for " << rows << "x" << colms << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                cin >> data[i][j];
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        if (rows != other.rows || colms != other.colms) {
            throw MismatchException(rows, colms, other.rows, other.colms);
        }

        Matrix<T> result(rows, colms);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < colms; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};


int main() {
    try {
        Matrix<int> m1(2, 2);
        Matrix<int> m2(2, 2);
        Matrix<int> m3(3, 2); 

        cout << "Matrix 1:\n";
        m1.input();
        cout << "Matrix 2:\n";
        m2.input();

        Matrix<int> result = m1 + m2;
        cout << "Result of addition:\n";
        result.print();

        
        Matrix<int> fail = m1 + m3;
    } 
    catch (const MismatchException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
