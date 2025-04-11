#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixH {
public:
    void updateElement(Matrix2x2 &mat, int row, int col, int value);
};

class Matrix2x2 {
private:
    int m[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2 &other) const {
        return Matrix2x2(
            m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
            m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2 &other) const {
        return Matrix2x2(
            m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
            m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2 &other) const {
        return Matrix2x2(
            m[0][0]*other.m[0][0] + m[0][1]*other.m[1][0],
            m[0][0]*other.m[0][1] + m[0][1]*other.m[1][1],
            m[1][0]*other.m[0][0] + m[1][1]*other.m[1][0],
            m[1][0]*other.m[0][1] + m[1][1]*other.m[1][1]
        );
    }

    friend int determinant(const Matrix2x2 &mat);

    friend ostream& operator<<(ostream &out, const Matrix2x2 &mat) {
        out << mat.m[0][0] << " " << mat.m[0][1] << endl;
        out << mat.m[1][0] << " " << mat.m[1][1] << endl;
        return out;
    }

    friend class MatrixH;
};

int determinant(const Matrix2x2 &mat) {
    return (mat.m[0][0] * mat.m[1][1]) - (mat.m[0][1] * mat.m[1][0]);
}

void MatrixH::updateElement(Matrix2x2 &mat, int row, int col, int value) {
    if (row >= 0 && row < 2 && col >= 0 && col < 2) {
        mat.m[row][col] = value;
    } else {
        cout << "Invalid indices for update!" << endl;
    }
}

int main() {
    Matrix2x2 mat1(0, 9, 8, 7);
    Matrix2x2 mat2(3, 4, 5, 6);

    Matrix2x2 sum = mat1 + mat2;
    Matrix2x2 diff = mat1 - mat2;
    Matrix2x2 product = mat1 * mat2;

    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;
    cout << "Sum:\n" << sum;
    cout << "Difference:\n" << diff;
    cout << "Product:\n" << product;

    cout << "Determinant of Matrix 1: " << determinant(mat1) << endl;

    MatrixH helper;
    helper.updateElement(mat1, 4, 0, 3);

    cout << "Matrix 1 after update:\n" << mat1;

    return 0;
}
