class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector <vector<string>> res;
        unordered_map <string, int> entry;
        for (int i = 0; i < (int)strs.size(); i++) {
            string tmp = strs[i];
            sort (tmp.begin(), tmp.end());
            unordered_map<string, int>:: const_iterator got = entry.find(tmp);
            if (got == entry.end()) {
                entry[tmp] = res.size();
                vector <string> t (1, strs[i]);
                res.push_back (t);
            }
            else {
                res[entry[tmp]].push_back (strs[i]);
            }
        }
        return res;
        
    }
};
