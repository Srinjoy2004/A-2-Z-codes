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
