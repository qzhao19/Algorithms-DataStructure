class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, nums, cur, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int index) {
        if(cur.size() >= 2) res.push_back(cur);
        unordered_set<int> st;
        for(int i = index; i < nums.size(); i++) {
            if(cur.size() && cur.back() > nums[i]) continue;
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            cur.push_back(nums[i]);
            helper(res, nums, cur, i + 1);
            cur.pop_back();
        }
    }
};
