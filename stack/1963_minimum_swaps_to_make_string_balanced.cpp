//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/


class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() == false && st.top() == '[' && s[i] == ']')
                st.pop();
            else
                st.push(s[i]);
        }
        int st_size = st.size();
        string temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        // reverse(temp.begin(),temp.end());
        return ((temp.size() / 2) + 1) / 2;
    }
};