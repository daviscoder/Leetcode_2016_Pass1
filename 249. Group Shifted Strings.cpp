class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> myMap;
        vector<vector<string>> res;
        for (int i = 0; i < strings.size(); i++) {
            string tmp = strings[i];
            int offset = tmp[0] - 'a';
            tmp[0] = 'a';
            for (int j = 1; j < tmp.size(); j++) {
                tmp[j] -= offset;
                if (tmp[j] < 'a')
                    tmp[j] += 26;
            }
            if (myMap.count (tmp) == 0)
                myMap[tmp] = vector<string> (1, strings[i]);
            else
                myMap[tmp].push_back (strings[i]);
        }
        for (auto it : myMap) {
            res.push_back (it.second);
        }
        return res;
    }
};
