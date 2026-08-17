class Solution {
public:
    string removeDuplicates(string s) {
        int s_size = s.length();
        stack<char> st;
        for (int i = 0; i < s_size; i++) {
            if (!st.empty() && s[i] == st.top()) {
                st.pop();
            }
            else
            st.push(s[i]);
        }
        string res;
        while(!st.empty())
        {
            res=st.top()+res;
            st.pop();
        }
        return res;

    }
};