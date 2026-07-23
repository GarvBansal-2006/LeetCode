class Solution {
    void generate(vector<string>& result, string current, int open, int close,int n) {

        if ((int)current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            generate(result, current + "(", open + 1, close, n);
        }

        if (close < open) {
            generate(result, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", 0, 0, n);
        return result;
    }
};