class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int totalRows = matrix.size();
        int totalCols = matrix[0].size();
        vector<int> result;

        int top = 0, bottom = totalRows - 1;
        int left = 0, right = totalCols - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // Traverse from top to bottom
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // Traverse from right to left 
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};