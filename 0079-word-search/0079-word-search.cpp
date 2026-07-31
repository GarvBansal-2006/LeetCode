class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>>& board, string& word, int i, int j,
                int idx) {
        // Base case: all characters matched
        if (idx == word.size())
            return true;

        // Out of bounds OR mismatch
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        char temp = board[i][j]; // save state
        board[i][j] = '#';       // mark visited

        // Recurse in 4 directions
        bool found = search(board, word, i + 1, j, idx + 1) ||
                     search(board, word, i - 1, j, idx + 1) ||
                     search(board, word, i, j + 1, idx + 1) ||
                     search(board, word, i, j - 1, idx + 1);

        board[i][j] = temp; // backtrack (restore character)
        return found;
    }
};