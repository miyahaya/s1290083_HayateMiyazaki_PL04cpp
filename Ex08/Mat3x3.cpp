#include "Mat3x3.h"

Mat3x3::Mat3x3() {
    // デフォルトコンストラクタで単位行列を作成
    coeffs[0] = 1.0f; coeffs[1] = 0.0f; coeffs[2] = 0.0f;
    coeffs[3] = 0.0f; coeffs[4] = 1.0f; coeffs[5] = 0.0f;
    coeffs[6] = 0.0f; coeffs[7] = 0.0f; coeffs[8] = 1.0f;
}

Mat3x3::Mat3x3(float coeffs[9]) {
    // 別のコンストラクタで配列から行列を作成
    for (int i = 0; i < 9; i++) {
        this->coeffs[i] = coeffs[i];
    }
}

Mat3x3 Mat3x3::operator+(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < 9; i++) {
        result.coeffs[i] = coeffs[i] + other.coeffs[i];
    }
    return result;
}

Mat3x3 Mat3x3::operator-(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < 9; i++) {
        result.coeffs[i] = coeffs[i] - other.coeffs[i];
    }
    return result;
}

Mat3x3 Mat3x3::operator*(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.coeffs[i * 3 + j] =
                coeffs[i * 3] * other.coeffs[j] +
                coeffs[i * 3 + 1] * other.coeffs[j + 3] +
                coeffs[i * 3 + 2] * other.coeffs[j + 6];
        }
    }
    return result;
}

Mat3x3& Mat3x3::operator+=(const Mat3x3& other) {
    for (int i = 0; i < 9; i++) {
        coeffs[i] += other.coeffs[i];
    }
    return *this;
}

Mat3x3& Mat3x3::operator-=(const Mat3x3& other) {
    for (int i = 0; i < 9; i++) {
        coeffs[i] -= other.coeffs[i];
    }
    return *this;
}

Mat3x3& Mat3x3::operator*=(const Mat3x3& other) {
    Mat3x3 temp = *this * other;
    *this = temp;
    return *this;
}

Mat3x3 Mat3x3::operator-() const {
    Mat3x3 result;
    for (int i = 0; i < 9; i++) {
        result.coeffs[i] = -coeffs[i];
    }
    return result;
}

float Mat3x3::operator()(int i, int j) const {
    return coeffs[i * 3 + j];
}

bool Mat3x3::operator==(const Mat3x3& other) const {
    for (int i = 0; i < 9; i++) {
        if (std::abs(coeffs[i] - other.coeffs[i]) > 0.0001f) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Mat3x3& matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << matrix(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}