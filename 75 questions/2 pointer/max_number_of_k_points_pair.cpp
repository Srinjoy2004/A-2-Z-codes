//https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = 0;

        for (int i = 0; i < t.size() && index < s.size(); i++) {
            if (t[i] == s[index]) {
                index++;
            }
        }

        return index == s.size();
    }
};