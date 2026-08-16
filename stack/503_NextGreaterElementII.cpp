class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {

        stack<int> st;
        int s = arr.size();
        vector<int> res(s);
        for (int i = 2 * s - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % s]) {
                st.pop();
            }
            if (s > i) {
                if (!st.empty())
                    res[i % s] = st.top();
                else
                    res[i % s] = -1;
            }
            st.push(arr[i % s]);
        }
        return res;
    }
};