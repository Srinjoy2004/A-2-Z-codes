class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int s = temperatures.size();
        vector<int> res(s, 0);
        for (int i = s - 1; i >= 0; i--) {

            while (!st.empty() && st.top().first <= temperatures[i]) {

                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top().second - i;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};