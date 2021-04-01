#include<iostream>
using namespace std;

int gcd(int a, int b){
    
    if (a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    
    // int a, b;
    
    // while (cin >> a >> b){
    //     cout << (a * b) / gcd(a, b) << endl;
    // }

    // system("pause");
    // return 0;

    // cout << "hellow woerld"<< endl;

}