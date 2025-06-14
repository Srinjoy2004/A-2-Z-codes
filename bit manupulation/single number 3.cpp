//https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;
        // step 1
        for (int &num : nums) {
            xor_r = xor_r ^ num;
        }

        // step 2

        // finding the right most set bit

        int mask = xor_r & (-xor_r);
        int groupA = 0;
        int groupB = 0;

        // step 3
        for (int &num : nums) {
            if (num & mask)
                groupA = groupA ^ num;
            else
                groupB = groupB ^ num;
        }

        return {groupA, groupB};
    }
};