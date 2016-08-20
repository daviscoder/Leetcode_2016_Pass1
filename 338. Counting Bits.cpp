class Solution {
public:
    vector<int> countBits(int num) {
        if (num <= 0)
            return vector <int> (1, 0);
        vector <int> table (num + 1, 0);
        table[1] = 1;
        int limit = 2;
        for (int i = 2; i <= num; i *= 2) {
            for (int j = 0; j < limit && i + j <= num; j++) {
                table[i + j] = table[j] + 1;
            }
            limit *= 2;
        }
        return table;
    }
};
