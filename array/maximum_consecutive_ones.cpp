//https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int c = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                c++;
            else {

                c = 0;
            }
            maxi = max(maxi, c);
        }
        return maxi;
    }
};