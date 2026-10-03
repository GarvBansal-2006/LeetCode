class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> vec(n,false);
        for(int i=0; i<n; i++){
            char c = s[i];
            if(!st.empty() && s[st.top()]=='(' && c==')'){
                vec[st.top()] = true;
                vec[i] = true;
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        int maxlen = 0, count=0;
        for(int i=0; i<n; i++){
            if(vec[i]==true) count++;
            else count=0;
            maxlen = max(maxlen, count);
        }
        return maxlen;
        
    }
};