//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        vector<int>twosum;
        for (int i = 0; i < nums.size(); i++) {
            

            if (mymap.find(target-nums[i]) == mymap.end())
            {
                 mymap.insert({ nums[i],i});
            }else
            {
                twosum.push_back(mymap[target-nums[i]]);
                twosum.push_back(i);
                break;

            }
        }return twosum;
    }
};