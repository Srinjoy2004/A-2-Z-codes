// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// bruteforce

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }

        return -1;
    }
};

// optimal

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (high >= low)
        {
            int mid = (low + high) / 2;

            // if element is found
            if (nums[mid] == target)
                return mid;

            // checking whether left part is sorted or not
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
                // checking whether the right part is sorted or not
            }
            else if (nums[mid] <= nums[high])
            {
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};