class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        bool col0 = false, row0 = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        for (int i = 0; i < n; i++)
            if (matrix[0][i] == 0) {
                row0 = true;
                break;
            }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for (int i = 1; i < m; i++)
            if (matrix[i][0] == 0)
                setRow (matrix, i);
        for (int i = 1; i < n; i++)
            if (matrix[0][i] == 0)
                setCol (matrix, i);

        if (col0 == true)
            setCol (matrix, 0);
        if (row0 == true)
            setRow (matrix, 0);
    }
    void setRow (vector<vector<int>>& matrix, int row) {
        for (int i = 0; i < matrix[row].size(); i++)
            matrix[row][i] = 0;
    }
    void setCol (vector<vector<int>>& matrix, int col) {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][col] = 0;
    }
};
