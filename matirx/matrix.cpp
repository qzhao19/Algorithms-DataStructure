#include "matrix.hpp"
#include <iostream>

using namespace std;

void Matrix::initMat(){
    mat = new double *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        mat[i] = new double [n_cols];
    }
}


Matrix::Matrix (int n_rows_, int n_cols_) {
    n_cols = n_rows_;
    n_cols = n_cols_;

    initMat();

    for(int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = 0;
        }
    }
}


Matrix::Matrix (int n_rows_, int n_cols_, double val) {
    n_cols = n_rows_;
    n_cols = n_cols_;

    initMat();
    for(int i = 0; i < n_cols; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = val;
        }
    }
}


Matrix::~Matrix () {
    for (int i = 0; i < n_rows; i++) {
        delete[] mat[i];
    }

    delete[] mat;

}


Matrix& Matrix::operator=(const Matrix &M){
    if (this == &M){
        return *this;
    }

    if (n_rows != M.n_rows || n_cols != M.n_cols){
        for (int i = 0; i < n_rows; i++){
            delete[] mat[i];
        }
        delete[] mat;

        n_rows = M.n_rows;
        n_cols = M.n_cols;
        initMat();
    }

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = M.mat[i][j];
        }
    }

    return *this;
}


Matrix& Matrix::operator=(double *val) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] = *(val + i * n_cols + j);
        }
    }

    return *this;
}



Matrix& Matrix::operator+=(const Matrix &M) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++){
            mat[i][j] += M.mat[i][j];
        } 
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix &M) {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            mat[i][j] -= M.mat[i][j];
        }
    }

    return *this;
}



Matrix& Matrix::operator*=(const Matrix &M) {
    Matrix retmat(n_rows, M.n_cols, 0.0);
    for (int i = 0; i < n_rows; i ++) {
        for (int j = 0; j < M.n_cols; j++) {
            for (int k = 0; k < n_cols; k++) {
                retmat.mat[i][j] += (mat[i][k] * M.mat[k][j]); 
            }
        }
    }

    *this = retmat;

    return *this;
}


Matrix& Matrix::operator*(const Matrix &M) const{

    Matrix retmat(n_rows, M.n_cols, 0.0);
    for (int i = 0; i < n_rows; i ++) {
        for (int j = 0; j < M.n_cols; j++) {
            for (int k = 0; k < n_cols; k++) {
                retmat.mat[i][j] += (mat[i][k] * M.mat[k][j]); 
            }
        }
    }

    return retmat;
}


Matrix Matrix::hadamardProduct(const Matrix &A, const Matrix &B) {
   
    if ((A.n_cols != B.n_cols) || (A.n_rows != B.n_rows)) {
        cout << "MUST checkout the rows and column number!" <<endl;
    }

     Matrix retmat(A.n_rows, A.n_cols, 0.0);

    for (int i = 0; i < A.n_rows; i++) {
        for (int j = 0; j < A.n_cols; j++) {
            retmat.mat[i][j] = A.mat[i][j] * B.mat[i][j];
        }
    }

    return retmat;

}


Matrix Matrix::Solve(const Matrix &A, const Matrix &b) {
    // Gaussian elimination method 
    for (int i = 0; i < A.n_rows; i++) {
        if (A.mat[i][j] == 0) {
            
        }
    }

}


