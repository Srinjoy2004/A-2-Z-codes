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