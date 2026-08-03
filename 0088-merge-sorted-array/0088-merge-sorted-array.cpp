class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        int filled = m;

        while (j < n) {
            if (i < filled && nums1[i] <= nums2[j]) {
                i++;
            } else {
                for (int k = filled; k > i; k--) {
                    nums1[k] = nums1[k - 1];
                }
                nums1[i] = nums2[j];
                filled++;
                i++;
                j++;
            }
        }
    }
};