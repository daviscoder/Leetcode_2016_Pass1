class Solution {
public:
    vector<string> helper (int m, int n) {
        vector<string> res;
        if (n == 0) {
            res.push_back ("");
            return res;
        }
        if (n == 1) {
            res.push_back ("0");
            res.push_back ("1");
            res.push_back ("8");
            return res;
        }
        vector<string> sub = helper (m, n - 2);
        for (int i = 0; i < sub.size(); i++) {
            if (m != n)
                res.push_back ("0" + sub[i] + "0");
            res.push_back ("1" + sub[i] + "1");
            res.push_back ("8" + sub[i] + "8");
            res.push_back ("6" + sub[i] + "9");
            res.push_back ("9" + sub[i] + "6");
        }
        return res;
    }

    vector<string> findStrobogrammatic(int n) {
        return helper (n, n);
    }
};
