// fruits into basket
// brutefore
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int i, j;
        int len;
        int maxlen = 0;
        unordered_set<int> myset;
        for (i = 0; i < fruits.size(); i++)
        {
            len = 0;
            myset.clear();
            for (j = i; j < fruits.size(); j++)
            {
                myset.insert(fruits[j]);
                if (myset.size() > 2)

                {
                    break;
                }
                else
                {
                    len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};

// Time complexity -> O(N^2)

// better
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int k = 2;
        map<int, int> mymap;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while (r < fruits.size())
        {
            mymap[fruits[r]]++;
            if (mymap.size() > k)
            {
                while (mymap.size() > k)
                {
                    mymap[fruits[l]]--;
                    if (mymap[fruits[l]] == 0)
                        mymap.erase(fruits[l]);
                    l++;
                }
            }
            if (mymap.size() <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};
// time complexity -> O(2N)
// space complexity -> O(3)

// optimal

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int k = 2;
        map<int, int> mymap;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while (r < fruits.size())
        {
            mymap[fruits[r]]++;
            if (mymap.size() > k)
            {
                // while (mymap.size() > k) {
                mymap[fruits[l]]--;
                if (mymap[fruits[l]] == 0)
                    mymap.erase(fruits[l]);
                l++;
                // }
            }
            if (mymap.size() <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};

// time complexity ->O(n)
// space complexity->O(1)