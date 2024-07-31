//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int sum = 0;
        int c = 0;
        for (int i = 0; i < k; i++) {
            sum = sum + nums[i];
        }
        if ((sum / k) >= threshold)
            c++;

        int left = 0;
        int right = k - 1;
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[left];
            left++;
            right++;
            sum = sum + nums[right];
            if ((sum / k) >= threshold)
                c++;
        }

        return c;
    }
};