class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res (length, 0);
        for (int i = 0; i < updates.size(); i++) {
            int start = updates[i][0];
            int end = updates[i][1];
            int inc = updates[i][2];
            res[start] += inc;
            if (end + 1 < res.size())
                res[end + 1] -= inc;
        }
        for (int i = 1; i < res.size(); i++)
            res[i] += res[i - 1];
        return res;
    }
};
