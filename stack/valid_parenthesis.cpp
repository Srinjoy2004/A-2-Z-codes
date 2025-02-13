//https://leetcode.com/problems/valid-parentheses/description/


//bruteforce

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(char ch:s)
        {
            if(st.empty() || ch=='(' || ch=='{' || ch=='[' )
            {
                st.push(ch);

            }

            if (ch==')')
            {
                if(st.top() == '(')
                   st.pop();
                   else return false;
            }
            if (ch=='}')
            {
                if(st.top() == '{')
                   st.pop();
                   else return false;
            }
            if (ch==']')
            {
                if(st.top() == '[')
                   st.pop();
                   else return false;
            }
        }
        if(st.empty()==true)return true;
        else return false;
    }
};