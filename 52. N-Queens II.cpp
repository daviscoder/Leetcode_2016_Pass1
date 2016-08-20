class Solution {
public:
    bool checker (int m, int n, vector<string>& matrix) {
        int size = matrix.size();
        // check column.
        for (int i = 0; i < size; i++)
            if (matrix[i][n] == 'Q')
                return false;
        // check diagonal
        for (int i = 0; i < size; i++) {
            if (m - i >= 0 && n - i >= 0 && matrix[m - i][n - i] == 'Q')
                return false;
            if (m - i >= 0 && n + i < size && matrix[m - i][n + i] == 'Q')
                return false;
            if (m + i < size && n - i >= 0 && matrix[m + i][n - i] == 'Q')
                return false;
            if (m + i < size && n + i < size && matrix[m + i][n + i] == 'Q')
                return false;
        }
        return true;
    }
    void helper (int cnt, vector<string>& cur, int n, int row, int& res) {
        if (cnt == n) {
            res++;
            return;
        }
        for (int j = 0; j < n; j++) {
            if (checker (row, j, cur) == true) {
                cur[row][j] = 'Q';
                helper (cnt + 1, cur, n, row + 1, res);
                cur[row][j] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector <string> cur (n, string (n, '.'));
        int res = 0;
        helper (0, cur, n, 0, res);
        return res;
    }
};
