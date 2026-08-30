class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int minVal = INT_MAX, minIdx = 0;
        int maxVal = INT_MIN, maxIdx = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                maxIdx = i;
            }
            if(nums[i] < minVal){
                minVal = nums[i];
                minIdx = i;
            }
        }
        
        int n = nums.size();
        int l = min(minIdx, maxIdx);
        int r = max(maxIdx, minIdx);
        
        int fLeft = r + 1;
        int fRight = n - l;
        int diffSide = l + 1 + n - r;
        
        return min({fLeft, fRight, diffSide});
    }
};