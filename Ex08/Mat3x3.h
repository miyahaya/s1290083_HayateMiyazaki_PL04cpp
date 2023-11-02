#ifndef MAT3X3_H
#define MAT3X3_H

#include <iostream>

class Mat3x3 {
public:
    Mat3x3(); // デフォルトコンストラクタ
    Mat3x3(float coeffs[9]); // 別のコンストラクタ

    Mat3x3 operator+(const Mat3x3& other) const; // 加算
    Mat3x3 operator-(const Mat3x3& other) const; // 減算
    Mat3x3 operator*(const Mat3x3& other) const; // 乗算
    Mat3x3& operator+=(const Mat3x3& other); // 複合加算と代入演算子
    Mat3x3& operator-=(const Mat3x3& other); // 複合減算と代入演算子
    Mat3x3& operator*=(const Mat3x3& other); // 複合乗算と代入演算子
    Mat3x3 operator-() const; // 単項マイナス
    float operator()(int i, int j) const; // 要素へのアクセス
    bool operator==(const Mat3x3& other) const; // 等価比較

    friend std::ostream& operator<<(std::ostream& os, const Mat3x3& matrix); // ストリーム挿入演算子

private:
    float coeffs[9]; // 係数配列
};

#endif