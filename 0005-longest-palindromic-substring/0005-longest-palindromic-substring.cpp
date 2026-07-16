class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int i = 0;

        int best_len = 0, best_start = 0;
        while (i < n) {
            int l = i, r = i;
            while (r + 1 < n and s[r + 1] == s[i]) {
                r++;
            }

            i = r + 1;

            while (l - 1 >= 0 and r + 1 < n and s[l - 1] == s[r + 1]) {
                l--, r++;
            }

            int len = (r - l) + 1;
            if (len > best_len) {
                best_len = len;
                best_start = l;
            }
        }
        return s.substr(best_start, best_len);
    }
};