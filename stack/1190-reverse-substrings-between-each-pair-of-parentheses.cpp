//https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/


class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int c = 0;
        string result="";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(c);
            } else if (s[i] == ')') {
                int top = st.top();
                reverse(result.begin() + top, result.end());
                st.pop();
            } else {
                c++;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};