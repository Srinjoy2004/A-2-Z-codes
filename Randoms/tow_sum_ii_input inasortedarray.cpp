// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res;
        while (l < r)
        {
            if ((numbers[l] + numbers[r]) > target)
                r--;
            else if ((numbers[l] + numbers[r]) < target)
                l++;
            else
            {
                res.push_back(l + 1);
                res.push_back(r + 1);
                break;
            }
        }
        return res;
    }
};