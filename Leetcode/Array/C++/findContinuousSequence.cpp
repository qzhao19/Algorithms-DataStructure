class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int limit = target / 2;
        vector<int> seq;

        int sum = 0;
        vector<vector<int>> ans;
        for (int i = 1; i <= limit; i++) {
            for (int j = i; ; j++) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;

                } else if (sum == target) {
                    seq.clear();
                    for (int k = i; k <= j; k++) {
                        seq.push_back(k);
                    }
                    ans.push_back(seq);
                    sum = 0; break;
                }
            }
        }

        return ans;
    }
};