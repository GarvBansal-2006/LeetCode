class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        solve(s, 0, current, result);
        return result;
    }

private:
 
    void solve(const string& s, int start, vector<string>& current,vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                solve(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};