// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution
{
public:
    int help(vector<int> &nums, int goal)
    {
        int l = 0, r = 0, count = 0, sum = 0;
        int n = nums.size();
        if (goal < 0)
            return 0;
        else
        {

            while (r < n)
            {
                sum = sum + nums[r];
                while (sum > goal)
                {
                    sum = sum - nums[l];
                    l = l + 1;
                }
                count = count + (r - l + 1);
                r = r + 1;
            }
            return count;
        }
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return help(nums, goal) - help(nums, goal - 1);
    }
};

// Time-O(n)
// space-O(1)