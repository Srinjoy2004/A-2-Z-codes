

// Longest Substring Without Repeating Characters

// bruteforce
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int len;
        int maxlen = 0;
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
// O(N^2)

// better

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mymap;

        // for (int i = 0; i < 250; ++i) {
        //     mymap[i] = -1;
        // }
        int len;
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while (r < n)
        {
            if (mymap.find(s[r]) != mymap.end() && l <= mymap[s[r]])
            {
                l = mymap[s[r]] + 1;
            }
            // len =r-l+1;
            maxlen = max(r - l + 1, maxlen);
            mymap[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};
// O[n]