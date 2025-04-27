//https://leetcode.com/problems/sum-of-subarray-ranges/description/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long sumSubArrayMinimas(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> nseIndex(n, n);
        vector<int> pseIndex(n, -1);

        stack<int> st1;
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && nums[st1.top()] >= nums[i]) st1.pop();
            if (!st1.empty()) nseIndex[i] = st1.top();
            st1.push(i);
        } 

        stack<int> st2;
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && nums[st2.top()] > nums[i]) st2.pop();
            if (!st2.empty()) pseIndex[i] = st2.top();
            st2.push(i);
        }

        long long sum = 0;  // Initialize sum
        for (int i = 0; i < n; i++) {
            long long left = i - pseIndex[i];
            long long right = nseIndex[i] - i;
            sum = (sum + (left * right * nums[i] * 1LL));  // Prevent overflow
        }
        return sum;
    }

    long long sumSubArrayMaximas(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ngeIndex(n, n);
        vector<int> pgeIndex(n, -1);

        stack<int> st1;
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && nums[st1.top()] <= nums[i]) st1.pop();
            if (!st1.empty()) ngeIndex[i] = st1.top();
            st1.push(i);
        } 

        stack<int> st2;
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && nums[st2.top()] < nums[i]) st2.pop();
            if (!st2.empty()) pgeIndex[i] = st2.top();
            st2.push(i);
        }

        long long sum = 0;  // Initialize sum
        for (int i = 0; i < n; i++) {
            long long left = i - pgeIndex[i];
            long long right = ngeIndex[i] - i;
            sum = (sum + (left * right * nums[i] * 1LL));  // Prevent overflow
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sumMinimas = sumSubArrayMinimas(nums);
        long long sumMaximas = sumSubArrayMaximas(nums);
        return sumMaximas - sumMinimas;
    }
};