// stack approach

class Solution {
public:
    int Operate(int a, int b, string token) {
        int res=-1;
        if (token == "+")
             res = a + b;
        if (token == "-")
             res = a - b;
        if (token == "*")
             res = a * b;
        if (token == "/")
             res = a / b;
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                int res = Operate(b, a, tokens[i]);
                st.push(res);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

//lamba function approach
