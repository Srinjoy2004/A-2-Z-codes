// https://leetcode.com/problems/majority-element/

// better using hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int majority = NULL;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second > n / 2)
                majority = it.first;
        }
        return majority;
    }
};

// moore's voting algo (optimal)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majority = NULL;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                majority = nums[i];
                count = 1;
            } else {
                if (majority == nums[i])
                    count++;
                else
                    count--;
            }
        }
        return majority;
    }
};