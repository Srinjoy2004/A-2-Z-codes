//https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    // Initialize the results as -1 (for the case where no floor or ceiling is found)
    int floor_val = -1;
    int ceil_val = -1;

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == x) {
            // If x is found, both floor and ceiling are x itself
            return {a[mid], a[mid]};
        } else if (a[mid] < x) {
            // Update floor_val if a[mid] is less than x
            floor_val = a[mid];
            low = mid + 1;
        } else {
            // Update ceil_val if a[mid] is greater than x
            ceil_val = a[mid];
            high = mid - 1;
        }
    }

    // Return the pair of floor and ceiling values
    return {floor_val, ceil_val};
}