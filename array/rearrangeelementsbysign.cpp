//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// my own approach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        int j = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = pos[j];
                j++;
            } else {
                nums[i] = neg[k];
                k++;
            }
        }return nums;
    }
};

//optimal (learned from codestorywithmik)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int pi = 0;
        int ni = 1;
        for (int& num : nums) {
            if (num > 0) {
                result[pi] = num;
                pi = pi + 2;
            } else {
                result[ni] = num;
                ni = ni + 2;
            }
        }return result;
    }
};