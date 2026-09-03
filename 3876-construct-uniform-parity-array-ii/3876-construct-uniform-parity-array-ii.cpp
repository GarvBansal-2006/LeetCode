class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int len = nums1.size();
        int ebit = 1, obit = 1;
        int mine = INT_MAX, mino = INT_MAX;

        for (int i = 0; i < len; i++) {
            if (nums1[i] & 1) { ebit = 0; mino = min(nums1[i], mino); }
            else              { obit = 0; mine = min(nums1[i], mine); }
        }

        if (ebit || obit) return true;   
        return mino < mine; 
    }
};