//https://leetcode.com/problems/maximum-subarray/description/
//optimal way (kadane's algo)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};