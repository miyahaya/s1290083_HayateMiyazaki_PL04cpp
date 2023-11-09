#include"Mat3x3.h"

//N*Nの単位行列を作成する。
Mat3x3::Mat3x3(){
    coeffs = new float[N*N];
    for(int i = 0; i < N; i++){
        if(i%(N+1) == 0) coeffs[i] = 1.0f;
        else coeffs[i] = 0.0f;
    }
}

Mat3x3::Mat3x3(float coeffs[]){
    for (int i = 0; i < N*N; i++) {
        this->coeffs[i] = coeffs[i];
    }
}

Mat3x3 Mat3x3::operator+(const Mat3x3& other)const{
    Mat3x3 result;
    for (int i = 0; i < N*N; i++) {
        result.coeffs[i] = coeffs[i] + other.coeffs[i];
    }
    return result;
}

Mat3x3 Mat3x3::operator-(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < N*N; i++) {
        result.coeffs[i] = coeffs[i] - other.coeffs[i];
    }
    return result;
}

Mat3x3 Mat3x3::operator*(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result.coeffs[i * N + j] =
                coeffs[i * N] * other.coeffs[j] +
                coeffs[i * N + 1] * other.coeffs[j + N] +
                coeffs[i * N + 2] * other.coeffs[j + N*2];
        }
    }
    return result;
}

Mat3x3& Mat3x3::operator+=(const Mat3x3& other) {
    for (int i = 0; i < N; i++) {
        coeffs[i] += other.coeffs[i];
    }
    return *this;
}

Mat3x3& Mat3x3::operator-=(const Mat3x3& other) {
    for (int i = 0; i < N; i++) {
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
    for (int i = 0; i < N; i++) {
        result.coeffs[i] = -coeffs[i];
    }
    return result;
}

float Mat3x3::operator()(int i, int j) const {
    return coeffs[i * N + j];
}

bool Mat3x3::operator==(const Mat3x3& other) const {
    for (int i = 0; i < N; i++) {
        if (std::abs(coeffs[i] - other.coeffs[i]) > 0.0001f) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Mat3x3& matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            os << matrix(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}


void Mat3x3::pushN(int N){
    this->N = N;
}

int Mat3x3::getN()const{
    return N;
}