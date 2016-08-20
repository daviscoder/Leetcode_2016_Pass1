class Solution {
public:
    void dfs (string& s, vector<bool>& visited, string cur, vector<string>& res) {
        if (cur.size() == s.size()) {
            res.push_back (cur);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i] == false) {
                if (i > 0 && s[i] == s[i - 1] && visited[i - 1] == false)
                    continue;
                cur += s[i];
                visited[i] = true;
                dfs (s, visited, cur, res);
                cur.pop_back ();
                visited[i] = false;
            }
        }
    }

    vector<string> generatePalindromes(string s) {
        vector<string> res;
        int table[256] = {0};
        for (int i = 0; i < s.size(); i++)
            table[s[i]]++;
        char single = 0;
        string str = "";
        for (int i = 0; i < 256; i++) {
            if (single != 0 && table[i] % 2 == 1)
                return res;
            else if (single == 0 && table[i] % 2 == 1)
                single = i;
            if (table[i])
                str += string (table[i] / 2, char (i));
        }
        vector<bool> visited (str.size(), false);
        string cur = "";
        dfs (str, visited, cur, res);
        for (int i = 0; i < res.size(); i++) {
            string tmp = res[i];
            reverse (tmp.begin(), tmp.end());
            if (single == 0)
                res[i] = res[i] + tmp;
            else
                res[i] = res[i] + single + tmp;
        }
        return res;
    }
};
