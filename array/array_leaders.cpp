// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <algorithm>
class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[])
    {
        // Code here
        int maxi = INT_MIN;

        vector<int> res;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] >= maxi)
            {
                res.push_back(arr[i]);
            }
            maxi = max(arr[i], maxi);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};