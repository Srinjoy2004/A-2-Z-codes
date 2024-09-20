//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n;
      

      //calculating lower bound
        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        int ans1 = ans;


        //calculating index next to higher bound

        low = 0, high = n - 1;
        ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        int ans2 = ans - 1;

        //returning values
        if (ans1 < n && arr[ans1] == x && ans2 >= 0 && arr[ans2] == x) {
            return {ans1, ans2}; // return the valid range
        } else {
            return {-1, -1}; // return [-1, -1] if not found
        }
    }
};


