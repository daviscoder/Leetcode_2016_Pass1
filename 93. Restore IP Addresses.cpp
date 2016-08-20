class Solution {
public:
    bool valid_ip_segment (string s) {
        int n = stoi (s);
        if (s.size() == 1 && n < 10)
            return true;
        else if (s.size() == 2 && n < 100 && n >= 10)
            return true;
        else if (s.size() == 3 && n >= 100 && n <= 255)
            return true;
        return false;
    }
    
    void helper (vector<string>& res, vector<string>& cur, int start, string s) {
        cout << start << endl;
        if (cur.size() == 4 && start == s.size()) {
            string tmp;
            for (int i = 0; i < 3; i++)
                tmp += cur[i] + '.';
            tmp += cur[3];
            res.push_back (tmp);
            return;
        }
        for (int i = start; i < s.size() && i < start + 3; i++) {
            if (valid_ip_segment (s.substr (start, i - start + 1)) && (4 - cur.size() - 1) * 3 >= s.size() - i - 1) {
                cur.push_back (s.substr (start, i - start + 1));
                helper (res, cur, i + 1, s);
                cur.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector <string> res, cur;
        if (s.size() <= 3)
            return res;
        helper (res, cur, 0, s);
        return res;
    }
};
