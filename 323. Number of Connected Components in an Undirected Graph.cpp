// https://segmentfault.com/a/1190000004224298

class Solution {
public:
    int compress (vector<int>& nodes, int v) {
        while (v != nodes[v]) {
            nodes[v] = nodes[nodes[v]];
            v = nodes[v];
        }
        return v;
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes (n, 0);
        for (int i = 1; i < n; i++)
            nodes[i] = i;
        for (auto& e : edges) {
            int i = compress (nodes, e.first);
            int j = compress (nodes, e.second);
            nodes[i] = j;
        }
        int cnt = 0;
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i] == i)
                cnt++;
        return cnt;
    }
};
