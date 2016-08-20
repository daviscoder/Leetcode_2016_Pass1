class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res (rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            int tmp = 1;
            for (int j = 1; j < i; j++) {
                int t = res[j];
                res[j] = tmp + res[j];
                tmp = t;
            }
            res[i] = 1;
        }
        return res;
    }
};
