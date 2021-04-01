class Solution {
public:
    bool helper(vector<int> &postorder, int left, int right) {

        if (left >= right) {
            return true;
        }

        int mid;
        for (mid = 0; mid < right; mid++) {
            if (postorder[mid] > postorder[right]) {
                break;
            }
        }

        for (int k = mid + 1; k < right; k++) {
            if (postorder[k] < postorder[right]) {
                return false;
            }
        }

        return helper(postorder, left, mid - 1) && helper(postorder, mid, right - 1);

    }
    bool verifyPostorder(vector<int>& postorder) {

        if (postorder.size() <= 1) {
            return true;
        }

        return helper(postorder, 0, postorder.size() - 1);

    }
};