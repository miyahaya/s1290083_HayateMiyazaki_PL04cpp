# include<iostream>
# include"Mat3x3.h"

const int N = 3; 

class Mat : public MatN{
   
    private :
    float C[N][N];
    public:
    float* add(float** A, float** B)override{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    };
    float* sub(float** A, float** B)override{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    };
    float* mult(float** A, float** B)override{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    C[i][j] += A[i][j] * B[j][k];
                }
            }
        }

    };
    float* compadd(float A[], float B[])override
    ;
    float* compsub(float A[], float B[])override{

    };
    float* compmult(float A[], float B[])override{

    };
    float* minus(float A[], float B[])override{

    };
    float accsess(int i, int j)override{

    };
    bool equal(float A[], float B[])override{

    };
};