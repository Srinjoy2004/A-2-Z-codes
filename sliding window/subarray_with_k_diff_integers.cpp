// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

// bruteforce

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // int r = l = 0;
        int c = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            unordered_set<int> myset;
            for (int j = i; j < n; j++)
            {
                myset.insert(nums[j]);
                if (myset.size() == k)
                {
                    c++;
                    // break;
                }
                if (myset.size() > k)
                {
                    // c++;
                    break;
                }
            }
        }
        return c;
    }
};

// time->O(n2)
// space->O(n)

// optimal

#include <bits/stdc++.h>

class Solution
{
public:
    int helpme(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[nums[r]]++;
            while (mp.size() > goal)
            {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helpme(nums, k) - helpme(nums, k - 1);
    }
};
