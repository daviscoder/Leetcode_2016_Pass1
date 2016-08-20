class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() <= 0)
            return 0;
        int n = costs.size();
        vector<vector<int>> profit (n, vector<int> (3, 0));
        for (int i = 0; i < 3; i++)
            profit [0][i] = costs[0][i];
        for (int i = 1; i < n; i++) {
            cout << "dfje" << endl;
            profit[i][0] = min (profit[i - 1][1], profit[i - 1][2]) + costs[i][0];
            profit[i][1] = min (profit[i - 1][0], profit[i - 1][2]) + costs[i][1];
            profit[i][2] = min (profit[i - 1][0], profit[i - 1][1]) + costs[i][2];
        }
        return min (min (profit[n - 1][0], profit[n - 1][1]), profit[n - 1][2]);
    }
};
