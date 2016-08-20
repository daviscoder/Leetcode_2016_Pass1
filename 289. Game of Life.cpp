// if next generation lives: 10 or 11
// if next generation dies : 0 or 1

class Solution {
public:
    int count (vector<vector<int>>& board, int x, int y) {
        int cnt = 0;
        for (int i = max (0, x - 1); i <= min (x + 1, (int)board.size() - 1); i++) {
            for (int j = max (0, y - 1); j <= min (y + 1, (int)board[0].size() - 1); j++) {
                if (i != x || j != y) {
                    cnt += board[i][j] % 10;
                }
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int cnt = count (board, i, j);
                cout << i << "\t" << j << "\t" << cnt << endl;
                if (cnt == 3 || (cnt == 2 && board[i][j] == 1))
                    board[i][j] += 10;
            }
        }
        update (board);
    }
    void update (vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) 
                board[i][j] /= 10;
    }
};
