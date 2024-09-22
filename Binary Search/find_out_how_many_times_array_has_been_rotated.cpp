// https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int findKRotation(vector<int> &nums)
    {
        // Code Here

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;
        int i = -1;

        while (high >= low)
        {
            int mid = (low + high) / 2;

            // checking whether left part is sorted or not
            if (nums[low] <= nums[mid])
            {

                if (nums[low] < mini)
                {
                    i = low;
                    mini = nums[low];
                }

                low = mid + 1;
            }
            else if (nums[mid] <= nums[high])
            {

                if (nums[mid] < mini)
                {
                    i = mid;
                    mini = nums[mid];
                }

                high = mid - 1;
            }
        }
        return i;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1)
        {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends