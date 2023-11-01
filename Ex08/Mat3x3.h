#ifndef Mat3x3_h
#define Mat3x3_h

#include<iostream>

class MatN{

    public:
    MatN();
    MatN(float* C){
        // for(int i = 0; i < sizeof(C); i++){
        //     this -> C[i] = C[i];
        // }
    }

    virtual float* add(float** A, float** B) = 0;
    virtual float* sub(float** A, float** B) = 0;
    virtual float* mult(float** A, float** B) = 0;
    virtual float* compadd(float* A, float* B) = 0;
    virtual float* compsub(float* A, float* B) = 0;
    virtual float* compmult(float* A, float* B) = 0;
    virtual float* minus(float* A, float* B) = 0;
    virtual float accsess(int i, int j) = 0;
    virtual bool equal(float* A, float* B) = 0;
    

};

#endif