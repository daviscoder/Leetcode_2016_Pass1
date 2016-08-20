class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board, int x, int y) {
        // check box.
        vector <int> cnt (10, 0);
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[y / 3 * 3 + k][x / 3 * 3 + l] != '.') {
                    int num = board[y / 3 * 3 + k][x / 3 * 3 + l] - '0';
                    cnt [num]++;
                    if (cnt[num] > 1)
                        return false;
                }
            }
        }
        cnt.clear();
        cnt.resize(10, 0);

        for (int i = 0; i < 9; i++) {
            if (board[i][y] != '.') {
                int num = board[i][y] - '0';
                cnt [num]++;
                if (cnt[num] > 1)       
                    return false;
            }
        }
        cnt.clear();
        cnt.resize(10, 0);
        
        for (int i = 0; i < 9; i++) {
            if (board[x][i] != '.') {
                int num = board[x][i] - '0';
                cnt [num]++;
                if (cnt[num] > 1)       
                    return false;
            }
        }
        return true;
    }

    bool solver (vector <vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int k = 1; k < 10; k++) {
                        board[i][j] = k + '0';
                        if (isValidSudoku (board, i, j) == true) {
                            if(solver (board) == true)
                                return true;
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solver (board);
    }
};
