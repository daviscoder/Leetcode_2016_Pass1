class Solution {
public:
    bool canWin (string& s, int len) {
        for (int i = 0; i <= len - 2; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                bool wins = !canWin (s, len);
                s[i] = '+';
                s[i + 1] = '+';
                if (wins) return true;
            }
        }
        return false;
    }
    
    bool canWin(string s) {
        return canWin (s, s.size());
    }
};
