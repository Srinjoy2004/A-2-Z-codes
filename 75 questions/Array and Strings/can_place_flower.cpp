//https://leetcode.com/problems/can-place-flowers/description/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count_zero = 0;
        int size=flowerbed.size();
        for (int i = 0; i < flowerbed.size(); i++) {

            if (i == 0) {
                if (flowerbed[i] == 0 && (i + 1 >= size || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    count_zero++;
                }
            } else if (i == flowerbed.size() - 1) {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    count_zero++;
                }
            } else {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 &&
                    flowerbed[i + 1] == 0) {

                    count_zero++;
                    flowerbed[i] = 1;
                }
            }
        }

        if (count_zero >= n)
            return true;
        else
            return false;
    }
};