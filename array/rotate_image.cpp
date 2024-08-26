//https://leetcode.com/problems/rotate-image/



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns =
            rows; // since square matrix number of rows and columns are equal

            

        // transpose
        for (int i = 0; i < rows; i++) {
            for (int j = i; j < columns; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse
        for (int i = 0; i < rows; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};