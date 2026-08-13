class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

    unordered_map<char, char> mapST, mapTS;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];

       
        if (mapST.find(c1) != mapST.end()) {
            if (mapST[c1] != c2) return false;
        } else {
            mapST[c1] = c2;
        }

        
        if (mapTS.find(c2) != mapTS.end()) {
            if (mapTS[c2] != c1) return false;
        } else {
            mapTS[c2] = c1;
        }
    }
    return true;
    }
};