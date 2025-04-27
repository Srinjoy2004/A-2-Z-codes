//https://leetcode.com/problems/subsets/

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();     
            int subsets = (1 << n);  // Total number of subsets = 2^n
            vector<vector<int>> ans; // To store all subsets
    
            for (int num = 0; num < subsets;num++) {
                vector<int> list; 
                for (int i = 0; i < n; i++) { 
                    if (num & (1 << i)) {     // If the ith bit is set in num
                        list.push_back(nums[i]);
                    }
                }
                ans.push_back(list); // Add current subset to the answer
            }
            return ans;
        }
    };
    