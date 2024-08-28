// https://leetcode.com/problems/majority-element-ii/description/

// using hashmaps
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++)
        {
            mymap[nums[i]]++;
        }
        int n = nums.size();
        nums.clear();
        for (auto it : mymap)
        {
            if (it.second > n / 3)
                nums.push_back(it.first);
        }
        return nums;
    }
};

// optimal
// modified moores voting algo

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int first = nums[0];
        int second = nums[0];
        int fc = 0;
        int sc = 0;
        if (nums.size() < 2)
            return nums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (first == nums[i])
                fc++;
            else if (second == nums[i])
                sc++;
            else if (fc == 0)
            {
                first = nums[i];
                fc = 1;
            }
            else if (sc == 0)
            {
                second = nums[i];
                sc = 1;
            }
            else
            {
                sc--;
                fc--;
            }
        }
        if (first == second)
            return {first};
        fc = 0;
        sc = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == first)
                fc++;
            if (nums[i] == second)
                sc++;
        }
        vector<int> res;
        if (fc > floor(nums.size() / 3))
            res.push_back(first);
        if (sc > floor(nums.size() / 3))
            res.push_back(second);
        return res;
    }
};
