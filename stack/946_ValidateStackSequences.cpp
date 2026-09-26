class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int m = pushed.size();
        int n = popped.size();
        stack<int> st;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            st.push(pushed[i]);
            while (st.empty() == false && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
        }
        return (st.empty());
    }
};