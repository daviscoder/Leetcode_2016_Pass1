class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <vector<int>> matrix (n, vector<int> (n, 0));
        int len = n * n, p = 1, round = 0;
        while (p <= len) {
            for (int i = round; i < n - round && p <= len; i++) {
                matrix[round][i] = p;
                p++;
            }
            for (int i = round + 1; i < n - round && p <= len; i++) {
                matrix[i][n - 1 - round] = p;
                p++;
            }
            for (int i = n - 2 - round; i >= round && p <= len; i--) {
                matrix[n - 1 - round][i] = p;
                p++;
            }
            for (int i = n - 2 - round; i > round && p <= len; i--) {
                matrix[i][round] = p;
                p++;
            }
            round++;
        }
        return matrix;
    }
};
