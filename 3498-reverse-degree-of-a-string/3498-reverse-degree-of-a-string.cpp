class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, i, n = s.size(), x;
        for (i = 0; i < n; i++) {
            x = 26 - (s[i] - 'a');
            ans = ans + (i + 1) * x;
        }
        return ans;
    }
};