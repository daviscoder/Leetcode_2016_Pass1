class Solution {
public:
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        if (s.size() <= 1) return s;
        int p = 0, q = s.size() - 1;
        while (p < q) {
            if (isVowel (s[p]) && isVowel (s[q])) {
                char tmp = s[p];
                s[p] = s[q];
                s[q] = tmp;
                p++;
                q--;
            }
            else if (isVowel (s[p]))
                q--;
            else if (isVowel (s[q]))
                p++;
            else {
                p++;
                q--;
            }
        }
        return s;
    }
};
