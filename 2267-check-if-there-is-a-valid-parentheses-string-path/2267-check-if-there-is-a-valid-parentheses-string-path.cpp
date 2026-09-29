class Solution {
public:
    bool solve(int row, int col, int count, int m, int n,
               vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {

        if (row >= m || col >= n)
            return false;

        if (dp[row][col][count] != -1)
            return dp[row][col][count];

        int newCount = count;

        if (grid[row][col] == '(')
            newCount++;
        else
            newCount--;

    
        if (newCount < 0)
            return dp[row][col][count] = false;

        if (row == m - 1 && col == n - 1) {
            return dp[row][col][count] = (newCount == 0);
        }

        return dp[row][col][count] =
            solve(row + 1, col, newCount, m, n, grid, dp) ||
            solve(row, col + 1, newCount, m, n, grid, dp);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(2 * (m + n), -1))
        );

        return solve(0, 0, 0, m, n, grid, dp);
    }
};