class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {

        int result = -1;
        vector<unordered_set<int>> graph1(N+1);
        vector<unordered_set<int>> graph2(N+1);

        for (auto &t : trust) {
            graph1[t[0]].insert(t[1]);
            graph2[t[1]].insert(t[0]);
        }

        for (int i = 1; i <= N; i++) {
            if (graph1[i].size() == 0 && graph2[i].size() == N-1) {
                result = i;
                break;
            }
        }

        return result;
    }
};