//https://leetcode.com/problems/maximum-score-from-removing-substrings/description/



class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a';
        char b = 'b';
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
            // char temp1 = a;
            // a = b;
            // b = temp;
            a='b';
            b='a';
        }
        stack<char> st;
        int score = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() == b && s[i] == a) {
                score = score + y;
                st.pop();
            } else
                st.push(s[i]);
        }
        int size = st.size();
        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        stack<char> sti;
        for (int i = 0; i < result.size(); i++) {
            if (!sti.empty() && sti.top() == a && result[i] == b) {
                score = score + x;
                sti.pop();
            } else
                sti.push(result[i]);
        }
        return score;
    }
};