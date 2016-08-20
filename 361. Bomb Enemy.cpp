class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() <= 0 || grid[0].size() <= 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> horizontal (m, vector<int> (n, 0));
        vector<vector<int>> portrait (m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            int start = 0, cnt = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    cnt++;
                if (grid[i][j] == 'Y') {
                    for (int k = start; k < j; k++)
                        if (grid[i][k] == '0') {
                            horizontal[i][k] = cnt;
                        }
                    start = j + 1;
                    cnt = 0;
                }
            }
            for (int k = start; k < n; k++) {
                if (grid[i][k] == '0') {
                    horizontal[i][k] = cnt;
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            int start = 0, cnt = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 'X')
                    cnt++;
                if (grid[i][j] == 'Y') {
                    for (int k = start; k < i; k++)
                        if (grid[k][j] == '0')
                            portrait[k][j] = cnt;
                    start = i + 1;
                    cnt = 0;
                }
            }
            for (int k = start; k < m; k++)
                if (grid[k][j] == '0')
                    portrait[k][j] = cnt;
        }
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max (res, portrait[i][j] + horizontal[i][j]);
            }
        }
        return res;
        
    }
};
