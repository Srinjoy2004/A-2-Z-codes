//https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int res = INT_MIN;
        while (r > l) {
            int area = min(height[l], height[r]);
            int prod = area * (r-l);
            if (height[l] < height[r])
                l++;
            else
                r--;
            res = max(res, prod);
        }
        return res;
    }
};