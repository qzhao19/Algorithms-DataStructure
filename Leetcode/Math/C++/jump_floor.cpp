class Solution {
public:
    int jumpFloor(int number) {
        // Fibonacci problem
        if (number <= 2){
            return number;
        }
        
        long floor1 = 1;
        long floor2 = 2;
        long ans = 0;
        
        for (int i = 3; i <= number; i++){
            ans = floor1 + floor2;
            
            floor1 = floor2;
            floor2 = ans;
        }
        return ans;
    }
};