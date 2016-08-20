class Solution {
public:
    string say (string s) {
        int i = 0, cnt = 1;
        string res;
        while (i < s.length()) {
            while (i < (int)s.length() - 1 && s[i + 1] == s[i]) {
                cnt++;
                i++;
            }
            if (i == (int)s.length() - 1) {
                res += to_string(cnt);
                res += s[i];
                return res;
            }
            
            res += to_string(cnt);
            res += s[i];
            cnt = 1;
            i++;
        }
        return res;
    }
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++) {
            s = say (s);
        }
        return s;
    }
};
