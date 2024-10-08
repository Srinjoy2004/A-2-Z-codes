//https://leetcode.com/problems/kth-missing-positive-number/

//linear search

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int num = 1;

        int n = arr.size();
        int i = 0;
        int k_check = 0;
        int num = 1;
        while (k_check < k) {

            if (i < arr.size() && arr[i] == num) {
                i++;
            } else {
                k_check++;
            }

            if (k_check == k) {
                return num;
            }
            num++;
        }
        return -1;
    }
};
