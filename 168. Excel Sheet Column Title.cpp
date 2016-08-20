class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            s += (n - 1) % 26 + 'A';
            n = (n - 1) / 26;
        }
        reverse (s.begin(), s.end());
        return s;
    }
};
