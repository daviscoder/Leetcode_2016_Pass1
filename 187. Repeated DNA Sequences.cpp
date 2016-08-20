class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        for (int i = 0; i + 9 < s.size(); i++) {
            string tmp = s.substr (i, 10);
            if (map[tmp] == 1)
                res.push_back (tmp);
            map[tmp]++;
        }
        return res;
    }
};
