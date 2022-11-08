class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        int n = s.size();
        for (int i=n-1;i>=0;i--) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (st.top() == s[i]-32 || st.top() == s[i]+32) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        
        string res = "";
        while (!st.empty()) {
            char c = st.top();
            st.pop();
            res.push_back(c);
        }
        
        
        return res;
        
    }
};