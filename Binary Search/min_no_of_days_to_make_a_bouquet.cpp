//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int can(vector<int>& bloomDay, int mid, int k) {

        int Bouq_count = 0;
        int consecutive_count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consecutive_count++;
            } else {
                consecutive_count = 0;
            }
            if (consecutive_count == k) {
                Bouq_count++;
                consecutive_count = 0;
            }
        }

        return Bouq_count;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        int start_day = 1;
        int end_day = *max_element(begin(bloomDay), end(bloomDay));

        int min_days = -1;
        while (end_day >= start_day) {
            int mid = start_day + (end_day - start_day) / 2;
            if (can(bloomDay, mid, k) >= m) {
                min_days = mid;
                end_day = mid - 1;
            } else {
                start_day = mid + 1;
            }
        }
        return min_days;
    }
};