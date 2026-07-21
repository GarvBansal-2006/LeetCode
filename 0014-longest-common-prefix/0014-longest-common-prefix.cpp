class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

    string prefix = strs[0];
    int prefixLength = prefix.size();

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;
        while (j < prefixLength && j < strs[i].size() && prefix[j] == strs[i][j]) {
            j++;
        }
        prefixLength = j; 

        if (prefixLength == 0) return "";
    }

    return prefix.substr(0, prefixLength);
    }
};