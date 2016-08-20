class Solution {
public:
    int cnt;
    int find (int x, vector<int>& parent) {
        if (x == parent[x]) return x;
        return find (parent[x], parent);
    }
    
    bool uni (int a, int b, vector<int>& parent, vector<int>& rank) {
        int x = find (a, parent);
        int y = find (b, parent);
        if (x == y) return false; // a loop detected;
        if (rank [x] > rank [y])
            parent[y] = x;
        else if (rank [x] < rank [y])
            parent[x] = y;
        else {
            parent[y] = x;
            rank[x]++;
        }
        cnt--;
        return true;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n < 1) return false;
        vector<int> parent (n);
        vector<int> rank (n, 0);
        cnt = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < edges.size(); i++) {
            if (uni (edges[i].first, edges[i].second, parent, rank) == false)
                return false;
        }
        return cnt == 1;
    }
};
