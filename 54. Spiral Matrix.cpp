class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        int m = matrix.size(), n = matrix[0].size(), len = m * n, p = 0, round = 0;
        while (p < len) {
            for (int i = round; i < n - round && p < len; i++) {
                res.push_back(matrix[round][i]);
                p++;
            }
            for (int i = round + 1; i < m - round && p < len; i++) {
                res.push_back (matrix[i][n - 1 - round]);
                p++;
            }
            for (int i = n - 2 - round; i >= round && p < len; i--) {
                res.push_back (matrix[m - 1 - round][i]);
                p++;
            }
            for (int i = m - 2 - round; i > round && p < len; i--) {
                res.push_back (matrix[i][round]);
                p++;
            }
            round++;
        }
        return res;
    }
};
