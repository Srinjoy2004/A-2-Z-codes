https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n3 = INT_MIN;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (n3 > nums[i]) {
                return true;
            }
            while (st.empty() != true && st.top() < nums[i]) {
                n3 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};