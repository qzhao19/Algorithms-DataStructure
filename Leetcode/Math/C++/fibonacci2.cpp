class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 1){
            return n;
        }
        
        long fib1 = 0;
        long fib2 = 1;
        long ans = 0;
        
        for (int i = 2; i <= n; i++){
            ans = fib1 + fib2;
            fib1 = fib2;
            fib2 = ans;
        }
        return ans;
    }
};