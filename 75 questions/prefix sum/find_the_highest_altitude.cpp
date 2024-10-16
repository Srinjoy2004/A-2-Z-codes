//https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> res(gain.size() + 1);
        res[0]=0;
        for (int i = 1; i <= gain.size(); i++) {
            res[i] = res[i - 1] + gain[i - 1];
        }
        sort(res.begin(), res.end());
        return res[res.size() - 1];
    }
};