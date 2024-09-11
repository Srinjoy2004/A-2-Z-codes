//https://leetcode.com/problems/binary-search/description/

#include <cmath>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int m = floor((l + r) / 2);
        while (l <= r) {
            if (target == nums[m]) {
                return m;
                break;
            } else if (target > nums[m]) {

                l = m + 1;
                m = floor((l + r) / 2);
            } else {
                r = m - 1;
                m = floor((l + r) / 2);
            }
        }
        return -1;
    }
};