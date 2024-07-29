//https://leetcode.com/problems/maximum-average-subarray-i/description/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum = sum + nums[i];
        }
        int maxi = sum;
        // maxi = max(maxi, sum);
        int left = 0;
        int right = k - 1;
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[left];
            left++;
            right++;
            sum = sum + nums[right];
            maxi = max(maxi, sum);
        }
        double result = static_cast<double>(maxi) / k;
        return result;
    }
};