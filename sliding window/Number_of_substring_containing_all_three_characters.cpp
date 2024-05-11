// Number of Substrings Containing All Three Characters
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

//Only Gamla Approach

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int i=0,j=0,count=0;

        unordered_map<char, int> mpp;

        while(j<n)
        {
            mpp[s[j]]++;

            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1)
            {
                count += (n - j);

                mpp[s[i]]--;
                i++;
            }
            j++;
        }


        return count;
    }
};