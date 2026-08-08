class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {

            while (left < right && !isAlphaNum(s[left]))
                left++;

            while (left < right && !isAlphaNum(s[right]))
                right--;

            if (toLower(s[left]) != toLower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }

private:
    bool isAlphaNum(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        return c;
    }
};