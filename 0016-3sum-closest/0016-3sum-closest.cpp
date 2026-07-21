class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closesum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int currsum = nums[i] + nums[l] + nums[r];
                if (abs(currsum - target) < abs(closesum - target)) {
                    closesum = currsum;
                }
                if (currsum > target) {
                    --r;
                } else if (currsum < target) {
                    ++l;
                } else {
                    return target;  
                }
            }
        }
        return closesum;
    }
};