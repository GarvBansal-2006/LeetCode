class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rev = s;

        reverse(rev.begin(), rev.end());

        if (s != rev)
            return false;
        return true;
    }
};