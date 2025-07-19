//https://leetcode.com/problems/move-zeroes/


//bruteforce

//memory limit exceeded
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int c = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                temp.push_back(nums[i]);
            else
                c++;
        }
        for (int i = 0; i < c; i++) {
            temp.push_back(0);
        }
        nums = temp; 
       
    }
};

//optimal

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {

                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

// [0,1,0,3,12]