//https://leetcode.com/problems/missing-number/

//approach 1

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }
        int n = nums.size();
        return (n * (n + 1) / 2) - sum;
    }
};

//approach 2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res = res ^ i ^ nums[i];
        }
        return res;
    }
};

