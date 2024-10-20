// Max Consecutive Ones III
// bruteforce

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxlen = 0;
        int len;
        int temp;
        for (int i = 0; i < nums.size(); i++)
        {
            temp = 0;
            len = 0;
            for (int j = i; j < nums.size(); j++)
            {

                if (nums[j] == 0)
                {
                    temp++;
                }
                if (temp <= k)
                {
                    len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
                else
                    break;
            }
        }
        return maxlen;
    }
};
// Time complexity -> O(n^2)

// better

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int maxlen = 0;
        int len = 0;
        int r = 0;
        int l = 0;
        int zeros = 0;
        int n = nums.size();
        while (r < n)
        {
            if (nums[r] == 0)
            {
                zeros++;
                while (zeros > k)
                {
                    if (nums[l] == 0)
                    {
                        zeros--;
                        l++;
                    }
                }
                if (zeros <= k)
                {
                    len = r - l + 1;
                    maxlen = max(maxlen, len);
                }
            }
            r++;
        }
        return maxlen;
    }
};

// time complexity->O(2n)

// optimal

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0, maxlen = 0, zeros = 0, len = 0;
        while (r < nums.size())
        {
            if (nums[r] == 0)
                zeros++;
            if (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
            {
                len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};

// time complexity->O9n