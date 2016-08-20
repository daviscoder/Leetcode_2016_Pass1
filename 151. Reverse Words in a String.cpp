class Solution {
public:
    void reverseWords(string &s) {
        reverse (s.begin(), s.end());
        for (int i = 0; i < s.size();) {
            while (i < s.size() && s[i] == ' ') 
                s.erase (s.begin() + i);
            int j = i;
            while (j < s.size() && s[j] != ' ')
                j++;
            reverse (s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        if (!s.empty() && s[s.size() - 1] == ' ')
            s.resize(s.size() - 1);
    }
};
