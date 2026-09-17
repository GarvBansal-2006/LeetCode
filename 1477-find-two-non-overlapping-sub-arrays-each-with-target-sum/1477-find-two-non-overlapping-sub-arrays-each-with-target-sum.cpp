class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> dp(arr.size(),INT_MAX);
        int mini = INT_MAX;
        long long sum = 0;
        int l=arr.size()-1,r=arr.size()-1;
        while(l>=0){
            sum += arr[l];
            while(sum > target){
                sum -= arr[r--];
            }
            if(sum == target){
                mini = min(mini,r-l+1);
            }
            dp[l] = mini;
            l--;
        }
        if(dp[0] == INT_MAX){
            return -1;
        }

        int res = INT_MAX;
        l=0,r=0,sum=0;
        while(r<arr.size()){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l++];
            }

            if(sum == target){
                if(r+1 < arr.size() && dp[r+1] != INT_MAX){
                    res = min(res,r-l+1+dp[r+1]);
                }
                else{
                    break;
                }
            }
            r++;
        }
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};