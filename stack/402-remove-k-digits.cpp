class Solution {
public:
    string removeKdigits(string s, int k) {

        if (k >= s.size())
            return "0";

        stack<char> st;
        string result;
        for (int i = 0; i < s.size(); i++) {

            while (k > 0 && !st.empty() && st.top() - '0' > s[i] - '0') {
                st.pop();
                k--;
            }

            st.push(s[i]);
        }

        // leftover k: remove from the end of the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        int stack_size = st.size();
        for (int i = 0; i < stack_size; i++) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result), end(result));

        // strip leading zeros
        int flag = 0;
        while (flag < result.size() && result[flag] == '0')
            flag++;
        result = result.substr(flag);

        if (result.empty())
            return "0";
        return result;
    }
};