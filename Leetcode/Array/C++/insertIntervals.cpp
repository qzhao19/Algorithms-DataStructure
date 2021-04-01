class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i;

        vector<vector<int>> result;

        for (i = 0; i < n; i++) {
            if (intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            }
            else {
                break;
            }
        }

        result.push_back(newInterval);

        for (; i < n; i++) {
            if (result.back()[1] < intervals[i][0]) {
                result.push_back(intervals[i]);
            }
            else {
                result.back()[0] = min(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }

        return result;
    }
};