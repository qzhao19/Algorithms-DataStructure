#include<iostream>

using namespace std;

int maxNumberOfOneBits(int n) {
    int count = 0, max_count = 0;
    
    while (n) {
        if (n & 1 == 1) {
            count++;
            max_count = max(max_count, count);
        } else {
            count = 0;
        }
        n >>= 1;
    }
    
    return max_count;
}

int main() {
    int n, ans;
    while (cin >> n) {
        ans = maxNumberOfOneBits(n);
        cout << ans << endl;
    }
    
    return 0;
}