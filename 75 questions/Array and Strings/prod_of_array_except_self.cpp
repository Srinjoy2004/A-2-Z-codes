//https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n, 1);  
        vector<int> right(n, 1); 
        int p_left = 1;
        int p_right = 1;

        // left prod
        for (int i = 0; i < nums.size(); i++) {
            p_left = p_left * nums[i];
            left[i]=p_left;
        }

        // right prod
        for (int i = nums.size() - 1; i >= 0; i--) {
            p_right = p_right * nums[i];
             right[i]=p_right;
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                res.push_back(right[1 + i]);

            else if (i == nums.size() - 1)
                res.push_back(left[i - 1]);

            else {
                res.push_back(left[i - 1] * right[i + 1]);
            }
        }
        return res;
    }
};