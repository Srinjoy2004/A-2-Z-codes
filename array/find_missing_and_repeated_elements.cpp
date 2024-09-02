//https://leetcode.com/problems/find-missing-and-repeated-values/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mymap;
        int n = grid.size() * grid.size();
        int actual_sum = 0;
        vector<int> res;

        // Populate the map and calculate the actual sum
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                mymap[grid[i][j]]++;
                actual_sum += grid[i][j];
            }
        }

        // Find the repeated number
        int num1 = 0;
        for (auto it : mymap) {
            if (it.second == 2) {
                num1 = it.first;
                res.push_back(num1);
                break;
            }
        }

        // Calculate the expected sum of numbers from 1 to n
        int expected_sum = n * (n + 1) / 2;

        // Find the missing number
        int num2 = expected_sum - (actual_sum - num1);
        res.push_back(num2);

        return res;
    }
};
