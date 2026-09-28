class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepthVal = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                if (depth > maxDepthVal)
                    maxDepthVal = depth;
            } else if (c == ')') {
                depth--;
            }
        }
        return maxDepthVal;
    }
};