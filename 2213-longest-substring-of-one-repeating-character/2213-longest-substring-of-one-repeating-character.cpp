
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();

        
        set<int> boundaries, lengths;
        vector<int> count(n + 1, 0); 

        auto addlen = [&](int len) {
            if (++count[len] == 1)
                lengths.insert(len);
        };

        auto removelen = [&](int len) {
            if (--count[len] == 0)
                lengths.erase(len);
        };

        boundaries.insert(0);
        boundaries.insert(n);
        int prev_idx = 0;
        
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i]) {
                boundaries.insert(i);
                addlen(i - prev_idx);
                prev_idx = i;
            }
        }
        addlen(n - prev_idx);

        auto update = [&](int i, bool set_boundary) {
            if (set_boundary) {
                auto it = boundaries.lower_bound(i);
                int next_val = *it;
                int prev_val = *std::prev(it);
                
                removelen(next_val - prev_val);
                addlen(i - prev_val);
                addlen(next_val - i);
                boundaries.insert(i);
            } else {
                auto it = boundaries.find(i);
                int prev_val = *std::prev(it);
                int next_val = *std::next(it);
                
                removelen(i - prev_val);
                removelen(next_val - i);
                addlen(next_val - prev_val);
                boundaries.erase(it);
            }
        };

        for (int i = 0; i < queryIndices.size(); ++i) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            
            if (idx > 0) {
                bool old_diff = s[idx - 1] != s[idx];
                bool now_diff = s[idx - 1] != c;
                if (old_diff != now_diff)
                    update(idx, now_diff);
            }
            if (idx + 1 < n) {
                bool old_diff = s[idx] != s[idx + 1];
                bool now_diff = c != s[idx + 1];
                if (old_diff != now_diff)
                    update(idx + 1, now_diff);
            }
            
            s[idx] = c;
            queryIndices[i] = *lengths.rbegin();
        }

        return move(queryIndices);
    }
};