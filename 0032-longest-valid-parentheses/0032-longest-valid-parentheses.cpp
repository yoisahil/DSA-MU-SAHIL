class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);          // base index for length calculation
        int maxLen = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);   // new base for next valid substring
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};