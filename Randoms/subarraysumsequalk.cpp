
//https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp.insert({0, 1});
        int res = 0;
        int cumsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cumsum = cumsum + nums[i];
            if (mpp.find(cumsum - k) != mpp.end()) {
                res = res + mpp[cumsum - k];
            } 
                mpp[cumsum]++;
        }
        return res;
    }
};
