//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;

        while (high >= low) {
            int mid = (low + high) / 2;

            // checking whether left part is sorted or not
            if (nums[low] <= nums[mid]) {
                mini = min(mini, nums[low]);
                low = mid + 1;

            } else if (nums[mid] <= nums[high]) {
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};