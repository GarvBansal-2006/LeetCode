class Solution {
public:
    int firstOccurance(vector<int>& arr, int n, int k)
{
    int l = 0;
    int r = n - 1;

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (arr[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}
int lastOccurance(vector<int>& arr, int n, int k)
{

    int l = 0;
    int r = n - 1;

    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (arr[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurance(nums, n, target);
        int last = lastOccurance(nums, n, target);
        return {first, last};
        
    }
};