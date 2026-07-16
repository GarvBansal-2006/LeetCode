class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] = true if substring s[i..j] is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1;
        int start = 0;

        // every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // check substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // check substrings of length >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        // build the result manually (no substr)
        string result = "";
        for (int i = start; i < start + maxLen; i++) {
            result.push_back(s[i]);
        }
        return result;
    }
};