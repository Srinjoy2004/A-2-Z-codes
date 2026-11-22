//https://leetcode.com/problems/parsing-a-boolean-expression/description/

class Solution {
public:
    char solve(char ch, vector<char>& vc) {
        if (ch == '!') {
            if (vc[0] == 't')
                return 'f';
            else
                return 't';
        }

        if (ch == '&') {
            for (int i = 0; i < vc.size(); i++) {
                if (vc[i] == 'f') {
                    return 'f';
                    break;
                }
            }
            return 't';
        }
        if (ch == '|') {
            for (int i = 0; i < vc.size(); i++) {
                if (vc[i] == 't') {
                    return 't';
                    break;
                }
            }
            return 'f';
        }
        return 'f';
    }
    bool parseBoolExpr(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',')
                continue;
            else if (s[i] == ')') {
                vector<char> temp;
                while (st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                int top = st.top();
                st.pop();
                st.push(solve(top, temp));
            } else
                st.push(s[i]);
        }
        if (st.top() == 't')
            return true;
        else
            return false;
    }
};