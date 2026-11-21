//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/



class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() == false && st.top() == '(' && s[i] == ')')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};