class Solution {
public:
    void DFS (vector<vector<char>>& board, int i, int j) {
        board[i][j] = '*';
        if (i > 1 && board[i - 1][j] == 'O') // top
            DFS (board, i - 1, j);
        if (j > 1 && board[i][j - 1] == 'O') // left
            DFS (board, i, j - 1);
        if (i < (int)board.size() - 1 && board[i + 1][j] == 'O') // bottom
            DFS (board, i + 1, j);
        if (j < (int)board[0].size() - 1 && board[i][j + 1] == 'O') // right
            DFS (board, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS (board, i, 0);
            if (board[i][n - 1] == 'O')
                DFS (board, i, n - 1);
        }
            
        for (int i = 1; i < n - 1; i++) {
            if (board[0][i] == 'O')
                DFS (board, 0, i);
            if (board[m - 1][i] == 'O')
                DFS (board, m - 1, i);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == '*')
                    board[i][j] = 'O';
    }
};
