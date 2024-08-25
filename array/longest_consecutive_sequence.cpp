//https://leetcode.com/problems/longest-consecutive-sequence/



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c = 1;
        int maxi = INT_MIN;
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 1)
                c++;
            else if (nums[i] - nums[i - 1] == 0)
                c = c;
            else
                c = 1;
            maxi = max(maxi, c);
        }
        return maxi;
    }
};