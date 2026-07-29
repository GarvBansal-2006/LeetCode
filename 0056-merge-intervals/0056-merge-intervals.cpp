class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int lastEnd = ans[ans.size()-1][1];   
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (lastEnd >= currStart) {
             
                ans[ans.size()-1][1] = max(lastEnd, currEnd);
            } else {
            
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};