class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 0) return 0;
        vector<int> tmp (ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1])
                tmp[i] = tmp[i - 1] + 1;
        }
        int res = tmp[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && tmp[i] <= tmp[i + 1])
                tmp[i] = tmp[i + 1] + 1;
            res += tmp[i];
        }
        return res;
    }
};
