class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        //cout << ans << endl;
        int div = 1;

        while((div & ans) == 0) {
            div <<= 1;
        }

        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (div & nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }

        return vector<int>{a, b};

    }
};