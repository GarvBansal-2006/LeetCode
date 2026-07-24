class Solution {
public:
    int search(vector<int>& nums, int target) {
        if( target == nums[0]){
 return 0;
        }
        if( target < nums[0]){
            for( int i = nums.size() - 1 ; i > 0 && target <= nums[i] ; i--){
                if(target == nums[i])
                return i;
            }
        }else {
            for ( int i = 0 ; i < nums.size() && target >= nums[i] ; i++){
                if(target == nums[i])
                return i;
            }
        }

        return -1;
    }
};