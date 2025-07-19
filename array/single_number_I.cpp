//https://leetcode.com/problems/single-number/description/


//bruteforce

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int maxi = INT_MIN;
        int res = -1;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        vector<int> v(maxi + 1, 0);
        for (int i = 0; i < n; i++) {
            v[nums[i]]++;
        }
        for (int i = 0; i <= maxi; i++) {
            if (v[i] == 1) {
                res = i;
                break;
            }
        }
        return res;
    }
};//facing error

//better

//hashmap

//optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = res ^ nums[i];
        }

        return res;
    }
};