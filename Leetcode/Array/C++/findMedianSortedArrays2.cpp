class Solution {
public:
    int findKthElement(vector<int> &nums1, int idx1, vector<int> &nums2, int idx2, int k) {
        if (idx1 >= nums1.size()) {
            return nums2[idx2 + k - 1];
        }

        if (idx2 >= nums2.size()) {
            return nums1[idx1 + k - 1];
        }

        if (k == 1) {
            return min(nums1[idx1], nums2[idx2]);
        }

        int mid_val1 = idx1 + k/2 - 1 < nums1.size() ? nums1[idx1 + k/2 - 1] : INT_MAX;
        int mid_val2 = idx2 + k/2 - 1 < nums2.size() ? nums2[idx2 + k/2 - 1] : INT_MAX;

        if (mid_val1 < mid_val2) {
            return findKthElement(nums1, idx1 + k/2, nums2, idx2, k - k/2);
        }
        else {
            return findKthElement(nums1, idx1, nums2, idx2 + k/2, k - k/2);
        }
    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int total_len = len1 + len2;

        return (findKthElement(nums1, 0, nums2, 0, (total_len + 1)/2) + findKthElement(nums1, 0, nums2, 0, (total_len + 2)/2)) / 2.0;

    }
};