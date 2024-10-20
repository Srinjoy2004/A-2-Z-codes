//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count_zero = 0;
        int maxi = INT_MIN;
        while (r <= nums.size() - 1) {
            if (nums[r] == 0)
                count_zero++;

            while (count_zero > 1) {

                if (nums[l] == 0) {

                    count_zero--;
                }

                l++;
            }

            int size = r - l + 1;
            r++;
            maxi = max(maxi, size);
        }
        return maxi - 1;
    }
};
