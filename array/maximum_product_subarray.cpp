//https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int prod = 1;
            for (int j = i; j < nums.size(); j++) {
                prod = prod * nums[j];
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
};

//optimal purely obs based

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suf=1;
        int ans=INT_MIN;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pre==0) pre=1;
            if(suf==0) suf=1;

            pre=pre*nums[i];
            suf=suf*nums[n-1-i];

            ans=max(ans,max(pre,suf));

        }return ans;
    }
};