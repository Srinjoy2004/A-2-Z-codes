//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cumsum = 0;
        unordered_map<int, int> mpp;
        mpp[0]++;
        int c=0;
        for (int i = 0; i < nums.size(); i++) {
            cumsum = cumsum + nums[i];
            if (mpp.find(cumsum - k) != mpp.end()) {
                c=c+mpp[cumsum-k];
            }
            mpp[cumsum]++;
        }
        return c;
    }
};