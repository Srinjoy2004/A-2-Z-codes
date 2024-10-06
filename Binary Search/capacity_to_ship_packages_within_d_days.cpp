//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    int daysreq(vector<int>& weights, int m) {
        int days = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum = sum + weights[i];
            if (sum > m) {
                sum = weights[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(begin(weights), end(weights));
        int high = 0;
        for (int i = 0; i < weights.size(); i++) {
            high = high + weights[i];
        }
        int res;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (daysreq(weights, mid) <= days) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};