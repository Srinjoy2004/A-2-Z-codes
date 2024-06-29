// https://leetcode.com/problems/longest-repeating-character-replacement/description/

// https://youtu.be/_eNhaDCr6P0?si=kh3mwRxonZgCjGfQ

// bruteforce

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i, j;
        // int hash[26] = {0};
        int maxlen = 0;
        int n = s.size();
        for (i = 0; i < n; i++)
        {
            int hash[26] = {0};
            int maxf = 0, changes = 0;
            for (j = i; j < n; j++)
            {
                hash[s[j] - 'A']++;

                maxf = max(maxf, hash[s[j] - 'A']);
                changes = (j - i + 1) - maxf;
                if (changes <= k)
                {
                    maxlen = max(maxlen, (j - i + 1));
                }
                else
                    break;
            }
        }

        return maxlen;
    }
};
// time -> O(n^2)
// space-> O(26)