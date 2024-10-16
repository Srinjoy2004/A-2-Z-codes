// https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> presum(n);
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            presum[i] = sum;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 && presum[n - 1] == presum[0])
                return 0;
            else if (i == n - 1 && presum[i - 1] == 0)
                return i;
            else if (i != 0 && presum[i - 1] == presum[n - 1] - presum[i])
                return i;
        }
        return -1;
    }
};