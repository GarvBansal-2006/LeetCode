class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int totalRows = matrix.size();
        int totalCols = matrix[0].size();

        int firstRowHasZero = 0;
        int firstColHasZero = 0;

        for (int c = 0; c < totalCols; c++) {
            if (matrix[0][c] == 0) {
                firstRowHasZero = 1;
                break;
            }
        }

        for (int r = 0; r < totalRows; r++) {
            if (matrix[r][0] == 0) {
                firstColHasZero = 1;
                break;
            }
        }

        // Mark rows and columns using first row/col
        for (int r = 1; r < totalRows; r++) {
            for (int c = 1; c < totalCols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Zero out cells based on markers
        for (int r = 1; r < totalRows; r++) {
            for (int c = 1; c < totalCols; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Zero first row if needed
        if (firstRowHasZero == 1) {
            for (int c = 0; c < totalCols; c++) {
                matrix[0][c] = 0;
            }
        }
        // Zero first column if needed
        if (firstColHasZero == 1) {
            for (int r = 0; r < totalRows; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};