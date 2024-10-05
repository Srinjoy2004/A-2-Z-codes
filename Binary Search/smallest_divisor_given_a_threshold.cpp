// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution
{
public:
    int checkdivisor(vector<int> &nums, int threshold, int mid)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1, r = *max_element(begin(nums), end(nums));
        int res = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (checkdivisor(nums, threshold, mid) <= threshold)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};