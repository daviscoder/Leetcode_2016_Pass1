class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 0)
            return 0;
        vector <int> table (128, -1);
        int begin = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (table[s[i]] >= begin) {
                cout << begin << "\t";
                res = max (res, i - begin);
                begin = table[s[i]] + 1;
                cout << begin << endl;
            }
            table[s[i]] = i;
        }
        res = max ((int)s.length() - begin, res);
        return res;
    }
};
