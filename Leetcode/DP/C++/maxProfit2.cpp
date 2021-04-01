class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_price = prices[0];
        int n = prices.size();
        vector<int> dp(n, 0);
        // dp[0] = 0;

        if (prices.size() == 0) {
            return 0;
        }
        for (int i = 1; i < prices.size(); i++) {
            min_price = min(prices[i], min_price);
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }

        return dp[n - 1];
    }
};