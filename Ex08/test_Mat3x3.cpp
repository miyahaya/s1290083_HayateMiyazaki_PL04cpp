#include <iostream>
#include "Mat3x3.h"

int main() {
    float coeffs1[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    float coeffs2[] = {9.0f, 8.0f, 7.0f, 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f};

    Mat3x3 matrix1(coeffs1);
    Mat3x3 matrix2(coeffs2);

    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    std::cout << matrix2 << std::endl;

    Mat3x3 sum = matrix1 + matrix2;
    std::cout << "Matrix Sum:" << std::endl;
    std::cout << sum << std::endl;

    Mat3x3 difference = matrix1 - matrix2;
    std::cout << "Matrix Difference:" << std::endl;
    std::cout << difference << std::endl;

    Mat3x3 product = matrix1 * matrix2;
    std::cout << "Matrix Product:" << std::endl;
    std::cout << product << std::endl;

    matrix1 += matrix2;
    std::cout << "Matrix 1 after addition assignment:" << std::endl;
    std::cout << matrix1 << std::endl;

    matrix1 -= matrix2;
    std::cout << "Matrix 1 after subtraction assignment:" << std::endl;
    std::cout << matrix1 << std::endl;

    matrix1 *= matrix2;
    std::cout << "Matrix 1 after multiplication assignment:" << std::endl;
    std::cout << matrix1 << std::endl;

    Mat3x3 negation = -matrix1;
    std::cout << "Negation of Matrix 1:" << std::endl;
    std::cout << negation << std::endl;

    float element = matrix1(1, 2);
    std::cout << "Element at (1, 2) of Matrix 1: " << element << std::endl;

    bool isEqual = matrix1 == matrix2;
    std::cout << "Matrix 1 and Matrix 2 are equal: " << (isEqual ? "Yes" : "No") << std::endl;

    return 0;
}