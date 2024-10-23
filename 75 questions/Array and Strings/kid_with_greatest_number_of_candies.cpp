//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(begin(candies), end(candies));
        vector<bool> res(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            candies[i] = candies[i] + extraCandies;
            if (candies[i] >= maxi)
                res[i] = true;
            else
                res[i] = false;
        }
        return res;
    }
};