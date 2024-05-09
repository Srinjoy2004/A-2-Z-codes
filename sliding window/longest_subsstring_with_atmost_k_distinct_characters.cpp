// Longest Substring with At Most K Distinct Characters
// https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410
// bruteforce

#include <bits/stdc++.h>
int kDistinctChars(int k, string &s)
{

    int maxlen = 0;
    map<char, int> mymap;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        mymap.clear();
        for (int j = i; j < n; j++)
        {
            mymap[s[j]]++;
            if (mymap.size() <= k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxlen;
}
// time complexity ->O(n^2)

// better and optimal approach same as fruit problem