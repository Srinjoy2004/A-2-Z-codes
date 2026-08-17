class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int s = prices.size();
        vector<int> res(s);
        stack<int> st;
        for (int i = s - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {

                st.pop();
            }
            if (!st.empty())
                res[i] = prices[i] - st.top();
            else
                res[i] = prices[i];
            st.push(prices[i]);
        }
        return res;
    }
};