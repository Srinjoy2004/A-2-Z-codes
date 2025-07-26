//https://leetcode.com/problems/rotate-image/



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int number_column = matrix[0].size();
        int number_row = matrix.size();

        // step 1 transpose
        for (int i = 0; i < number_row; i++) {
            for (int j = i+1; j < number_column; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // step 2 reverse
        for (int i = 0; i < number_column; i++)

        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};