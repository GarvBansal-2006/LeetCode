class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> result;
        string current;
        solve(digits, 0, current, result);
        return result;
    }

private:
    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void solve(const string& digits, int index, string& current,
               vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : mapping[digit]) {
            current.push_back(c);
            solve(digits, index + 1, current, result);
            current.pop_back();
        }
    }
};