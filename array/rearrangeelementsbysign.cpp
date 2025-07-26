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
        vector<int> res(nums.size());

       // int n=nums.size();
        int p = 0;
        int n = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res[p] = nums[i];
                p = p + 2;
            } else {
                res[n] = nums[i];
                n = n + 2;
            }
        }
        return res;
    }
};