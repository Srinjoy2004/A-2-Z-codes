//https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:

    int help(vector<int>& nums, int k) {
        int l = 0, r = 0, count = 0, sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                nums[i] = 0;
            else {
                nums[i] = 1;
                // c++;
            }
        }

        if (k < 0)
            return 0;
        else {

            while (r < n) {
                sum = sum + nums[r];
                while (sum > k) {
                    sum = sum - nums[l];
                    l = l + 1;
                }
                count = count + (r - l + 1);
                r = r + 1;
            }
            return count;
        }
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums, k) - help(nums, k - 1);
    }
};