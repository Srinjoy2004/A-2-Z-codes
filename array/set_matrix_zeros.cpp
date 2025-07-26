//https://leetcode.com/problems/set-matrix-zeroes/description/

//striver

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int row_size = matrix[0].size();//number of columns
        int column_size = matrix.size();//number of rows

        //step 1
        for (int i = 0; i < column_size; i++) {
            for (int j = 0; j < row_size; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if (j == 0) {
                        col0 = 0;
                    }

                    else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        //step 2
        for (int i = 1; i < column_size; i++) {
            for (int j = 1; j < row_size; j++) {
                if (matrix[0][j] == 0 || matrix[i][0]==0)
                    matrix[i][j] = 0;
            }
        }
        

        //step 3
        for (int i = 0; i < row_size; i++) {
            if (matrix[0][0] == 0)
                matrix[0][i] = 0;
        }

        //step 4
        for (int i = 0; i < column_size; i++) {
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};