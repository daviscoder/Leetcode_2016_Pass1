class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.size() == 0)
            return vector <string> ();
        if (words.size() == 1 && words[0].length() == 1 && maxWidth == 0)
            return vector <string> (1, "");
        int total = words.size(), i = 0;
        vector <string> res;
        while (i < total) {
            vector <string> curStr;
            int curLen = -1, wordLength = 0;
            while (i < total && curLen + words[i].length() + 1 <= maxWidth) {
                curStr.push_back (words[i]);
                curLen += 1 + words[i].length();
                wordLength += words[i].length();
                i++;
            }
            if (i == total) {
                res.push_back (lastLineBuild (curStr, maxWidth));
            }
            else {
                res.push_back (build (curStr, maxWidth, wordLength));
            }
        }
        return res;
    }
    
    static string lastLineBuild (vector <string> curStr, int maxWidth) {
        string res;
        for (int i = 0; i < curStr.size() - 1; i++) {
            res += curStr[i] + ' ';
        }
        res += curStr[curStr.size() - 1];
        if ((int)res.length() < maxWidth)
            res.insert (res.end(), maxWidth - res.length(), ' ');
        return res;
    }
    
    static string build (vector <string> curStr, int maxWidth, int wordLength) {
        string res;
        int totalSpaces = maxWidth - wordLength;
        for (int i = 0; i < curStr.size() - 1; i++) {
            res += curStr[i];
            if (totalSpaces % (curStr.size() - 1) > i)
                res.insert (res.end(), totalSpaces / (curStr.size() - 1) + 1, ' ');
            else
                res.insert (res.end(), totalSpaces / (curStr.size() - 1), ' ');
        }
        res += curStr[curStr.size() - 1];
        if ((int)res.length() < maxWidth)
            res.insert (res.end(), maxWidth - res.length(), ' ');
        return res;
    }
};
