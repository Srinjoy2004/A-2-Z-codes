

// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());
        vector<int> store;

        int l = 0;
        int r = skill.size() - 1;
        long long p = 0;
        while (l < r)
        {
            p = p + (skill[l] * skill[r]);

            store.push_back(skill[l] + skill[r]);
            l++;
            r--;
        }

        for (int i = 1; i < store.size(); i++)
        {
            if (store[i] != store[i - 1])
            {
                return -1;
                break;
            }
        }
        return p;
    }
};