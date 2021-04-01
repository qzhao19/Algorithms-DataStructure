# include<iostream>
# include<string.h>

using namespace std;

typedef long long LL;

const int M = 2;

struct Matrix{
    int mat[M][M];
    Matrix(){
        memset(mat, 0, sizeof(mat));
    }

    void unit(){
        mat[0][0] = mat[1][1] = 1;
        mat[0][1] = mat[1][0] = 0;
    }

    Matrix operator*(const Matrix &m) const {
        Matrix ans;

        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                for (int k = 0; k < M; k++){
                    ans.mat[i][j] += mat[i][k] * m.mat[k][j]; 
                }
            }
        }
        return ans;
    }

    Matrix operator^(int n) const{
        Matrix ans;
        ans.unit();

        Matrix A =* this;

        while (n){
            if (n&1) ans = ans * A;
            A = A * A;
            n >>= 1;
        }
        return ans;
    }

    void show(){
        cout << "Matrix : " <<endl;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main (){

    Matrix A;
    A.mat[0][0] = 0;
    A.mat[0][1] = A.mat[1][0] = A.mat[1][1] = 1;
    A.show();


    Matrix F;
    F.mat[0][0] = F.mat[1][0] = 1;
    F.mat[0][1] = F.mat[1][1] = 0;
    F.show();

    int n = 5;

    Matrix ans = (A ^ n) * F;
    ans.show();

    return 0; 
};