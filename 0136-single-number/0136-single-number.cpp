class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums) {
            if (s.count(x))
                s.erase(x);
            else
                s.insert(x);
        }
        return *s.begin();
    }
};