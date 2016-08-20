class Solution {
public:
    void helper (vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (i < 0 || j < 0 || i >= (int)grid.size() || j >= (int)grid[0].size()) return;
        if (grid[i][j] == '0' || visited[i][j] == true) return;
        visited[i][j] = true;
        helper (grid, visited, i - 1, j);
        helper (grid, visited, i, j - 1);
        helper (grid, visited, i + 1, j);
        helper (grid, visited, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int cnt = 0;
        vector <vector<bool>> visited (grid.size(), vector<bool> (grid[0].size(), false));
        for (int i = 0; i < (int)grid.size(); i++)
            for (int j = 0; j < (int)grid[0].size(); j++)
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    helper (grid, visited, i, j);
                    cnt++;
                }
        return cnt;
    }
};
