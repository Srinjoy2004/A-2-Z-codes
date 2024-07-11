// https://leetcode.com/problems/majority-element/

// better using hashmap
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res;
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); i++)
        {
            mymap[nums[i]]++;
        }
        for (auto it : mymap)
        {
            if (it.second > nums.size() / 2)
                res = it.first;
        }
        return res;
    }
};

// moore's voting algo (optimal)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int el;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                count = 1;
                el = nums[i];
            }
            else if (nums[i] == el)
                count++;
            else if (nums[i] != el)
                count--;
        }
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (el == nums[i])
                c++;
        }
        if (c > nums.size() / 2)
            return el;
        else
            return -1;
    }
};
