class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            while (i < s.size() && s[i] == ' ')
                i++;
            int cnt = 0;
            while (i < s.size() && s[i] != ' ') {
                cnt++;
                i++;
            }
            res = cnt == 0? res : cnt;
        }
        return res;
    }
};
