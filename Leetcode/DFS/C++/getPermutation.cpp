class Solution {
public:
    int factorial(int n) {
        int ans = 1;

        while (n) {
            ans *= n--;
        }
        return ans;
    }

    string getPermutation(int n, int k) {
        string ans;
        vector<int> nums;

        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        while (nums.size() > 0) {
            int index = nums.size();
            int fact = factorial(index - 1);

            index = (k - 1) / fact;
            ans += to_string(nums[index]);

            k = k - fact * index;
            nums.erase(nums.begin() + index);
        }

        return ans;
    }
};


class Solution {
private:
    string result;
    vector<bool> status;

public:
    int factorial(int n) {
        int result = 1;
        while (n > 0) {
            result *= n--;
        }
        return result;
    }

    void dfs(int n, int k) {
        int res_len = result.size();

        if (res_len == n) {
            return ;
        }

        for (int i = 1; i <= n; i++) {
            if (status[i] == true) {
                continue;
            }

            int cnt = factorial(n - res_len - 1);
            if (cnt < k) {
                k -= cnt;
                continue;
            }

            result += to_string(i);
            status[i] = true;
            dfs(n, k);
            return ;
        }
    }

    string getPermutation(int n, int k) {
        status.resize(n + 1, false);

        dfs(n, k);

        return result;
    }
};