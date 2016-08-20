class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> cToS;
        unordered_map<string, char> sToC;
        int i = 0;
        for (; i < pattern.size() && str.size() > 0; i++) {
            int pos = str.find_first_of (' ');
            pos = pos == -1? str.size() : pos;
            string word = str.substr (0, pos);
            if (cToS.count(pattern[i]) && cToS[pattern[i]] != word)
                return false;
            else if (sToC.count (word) && sToC[word] != pattern[i])
                return false;
            cToS[pattern[i]] = word;
            sToC[word] = pattern[i];
            str.erase (0, pos + 1);
        }
        if (i != pattern.size() || str.size() != 0)
            return false;
        return true;
    }
};
