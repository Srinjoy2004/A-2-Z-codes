//https://leetcode.com/problems/sort-colors/description/

//bruteforce

//sort using sort func time  complexity nlogn

//better

//intutive using loops and count

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0;
        int ones = 0;
        int two = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                zeros++;
            else if (nums[i] == 1)
                ones++;
            else if (nums[i] == 2)
                two++;
        }
        for (int i = 0; i < n; i++) {
            if (zeros > 0) {
                nums[i] = 0;
                zeros--;
            } else if (ones > 0) {
                nums[i] = 1;
                ones--;
            } else if (two > 0) {
                nums[i] = 2;
                two--;
            }
        }
    }
};

//O(n)

//optimal ---- Dutch National Flag Algo

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int m = 0;
        int h = n - 1;

        while (m <= h) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++ ;
            } else if (nums[m] == 1) {
                m++;
            } else {
                swap(nums[h], nums[m]);
                h--;
            }
        }
    }
};