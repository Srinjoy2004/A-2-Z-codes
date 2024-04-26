

// Longest Substring Without Repeating Characters

bruteforce class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int len;
        int maxlen = 00;
        for (int i = 0; i < s.size(); i++)
        {

            vector<int> v(250, 0);

            for (int j = i; j < s.size(); j++)
            {
                if (v[s[j]] == 1)
                {

                    break;
                }
                else
                {
                    v[s[j]] = 1;
                }

                len = j - i + 1;
                maxlen = max(len, maxlen);
                // return maxlen;
            }
        }
        return maxlen;
    }
};
