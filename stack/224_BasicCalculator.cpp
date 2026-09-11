class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        int result = 0;
        stack<int> st;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');

            } else if (s[i] == '+') {
                result = result + (sign * num);
                num = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result = result + (sign * num);
                num = 0;
                sign = -1;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                num = 0;
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result = result + (sign * num);
                int top_sign = st.top();
                st.pop();
                result = result * top_sign;
                result = result + st.top();
                st.pop();
                num = 0;
            }
        }
         result += sign * num; 
        return result;
    }
};