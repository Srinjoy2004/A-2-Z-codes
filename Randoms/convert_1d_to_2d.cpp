

//leetcode.com/problems/convert-1d-array-into-2d-array/description/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //vector<vector<int>> res;
        int index = 0;


        //for test case 3
        if (original.size() != m * n) {
            return {};
        }

        // Initialize the 2D vector with m rows and n columns
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = original[index];
                index++;
            }
        }
        return res;
    }
};

