class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= 0)
            return "";
        string res;
        vector <string> tmp (numRows, "");
        int cnt = 0;
        while (cnt < s.length()) {
            for (int i = 0; i < numRows && cnt < s.length(); i++) {
                tmp[i] += s[cnt];
                cnt++;
            }
            for (int i = numRows - 2; i > 0 && cnt < s.length(); i--) {
                tmp[i] += s[cnt];
                cnt++;
            }
        }
        for (int i = 0; i < numRows; i++)
            res += tmp[i];
        return res;
    }
};
