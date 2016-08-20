class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res (1, 0);
        for (int i = 0; i < n; i++)
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back ((1 << i) + res[j]);
        return res;
    }
};
