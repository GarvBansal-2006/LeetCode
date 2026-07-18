class Solution {
public:
    int findGCD(vector<int>& nums) {
        int lower = INT_MAX ;
        int higher = 0;
        for ( int i = 0 ; i < nums.size() ; i++){
            if(lower > nums[i]){
                lower = nums[i];
            }
            if(higher < nums[i]){
                higher = nums[i];
            }
        }
        return gcd(lower,higher);
    }
};