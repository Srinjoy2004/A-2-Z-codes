//https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  // Edge case: for 0 or 1
        
        int low = 1;
        int high = x;
        int res = 0;  // Initialize result
        
        while (low <= high) {  // Use low <= high
            int mid = low + (high - low) / 2;  // Prevent potential overflow
            
            if (mid <= x / mid) {  // Use division to avoid overflow
                res = mid;  // Store current mid as a valid result
                low = mid + 1;  // Move to the right half
            } else {
                high = mid - 1;  // Move to the left half
            }
        }
        
        return res;
    }
};