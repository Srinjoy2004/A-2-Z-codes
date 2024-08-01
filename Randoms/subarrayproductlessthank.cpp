//https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int prod = 1;
        int l = 0;
        int r = 0;
        int c = 0;
        while (r < nums.size()) {

            prod = prod * nums[r];
            while (prod >= k) {
                prod = prod / nums[l];
                l++;
            }

            c = c + (r - l + 1);
            r++;
        }
        return c;
    }
};
