class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // sort
        sort(people.begin(), people.end(), [](const vector<int> &u, const vector<int> &v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });

        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++) {
            int pos = people[i][1];
            result.insert(result.begin() + pos, people[i]);
        }

        return result;
    }
};