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
    void helper (vector<vector <string>>& res, int cnt, vector<string>& cur, int n, int row) {
        if (cnt == n) {
            res.push_back (cur);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (checker (row, j, cur) == true) {
                cur[row][j] = 'Q';
                helper (res, cnt + 1, cur, n, row + 1);
                cur[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector <vector <string>> res;
        vector <string> cur (n, string (n, '.'));
        helper (res, 0, cur, n, 0);
        return res;
    }
};
