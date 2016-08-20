class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return;
        sum = vector <vector<int>> (matrix.size() + 1, vector <int> (matrix[0].size() + 1, 0));
        sum[1][1] = matrix[0][0];
        for (int i = 1; i < matrix[0].size(); i++)
            sum[1][i + 1] = sum[1][i] + matrix[0][i];
        for (int i = 1; i < matrix.size(); i++)
            sum[i + 1][1] = sum[i][1] + matrix[i][0];
        for (int i = 2; i < sum.size(); i++) 
            for (int j = 2; j < sum[0].size(); j++) 
                sum[i][j] = -sum[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] + matrix[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1] - sum[row1][col2 + 1];
//        return 0;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
