class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> Q;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < rooms.size(); i++)
            for (int j = 0; j < rooms[0].size(); j++)
                if (rooms[i][j] == 0)
                    Q.push (make_pair (i, j));
        while (Q.empty() == false) {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            for (auto dir : dirs) {
                int i = x + dir.first, j = y + dir.second;
                if (i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size() || rooms[i][j] <= rooms[x][y] + 1)
                    continue;
                rooms[i][j] = rooms[x][y] + 1;
                Q.push (make_pair (i, j));
            }
        }
    }
};
