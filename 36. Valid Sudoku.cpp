class Solution {
public:


    bool isValidSudoku(vector<vector<char>>& board) {
        // check box.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                vector <int> cnt (10, 0);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i * 3 + k][j * 3 + l] != '.') {
                            int num = board[i * 3 + k][j * 3 + l] - '0';
                            cnt [num]++;
                            if (cnt[num] > 1)
                                return false;
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            vector <int> cnt (10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    cnt [num]++;
                    if (cnt[num] > 1)       
                        return false;
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            vector <int> cnt (10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    int num = board[j][i] - '0';
                    cnt [num]++;
                    if (cnt[num] > 1)       
                        return false;
                }
            }
        }
        return true;
    }
};
