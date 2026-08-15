class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int s = nums2.size();
        vector<int> res(nums1.size());
        unordered_map<int, int> mpp;
        stack<int> st;
        for (int i = s - 1; i >= 0; i--) {
            while (st.empty() == false && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty() == true) {
                mpp[nums2[i]] = -1;
            } else {
                mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = mpp[nums1[i]];
        }
        return res;
    }
};