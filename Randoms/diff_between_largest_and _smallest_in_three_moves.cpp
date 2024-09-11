

//https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

class Solution {
public:
    int minDifference(vector<int>& nums) {

        int n = nums.size();
        if (nums.size() <= 4)
            return 0;
        sort(nums.begin(), nums.end());

        int res = INT_MAX;
        res = min(res, nums[n - 4] - nums[0]);
        res = min(res, nums[n - 3] - nums[1]);
        res = min(res, nums[n - 2] - nums[2]);
        res = min(res, nums[n - 1] - nums[3]);
        return res;
    }
};

//time complexity is O(nlogn)
//notes- we have to play with 3 left extremes and 3 right extremes or their combinations
//combination in that way so that sum of left over elements of both extremes should be 3

