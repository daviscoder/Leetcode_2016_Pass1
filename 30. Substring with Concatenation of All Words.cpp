class Solution {
public:
    bool check (string s, unordered_map <string, int> wordCount, int wordSize, int totalWords, int start) {
        unordered_map <string, int> wordsFound;
        for (int i = 0; i < totalWords; i++) {
            string str = s.substr (start + i * wordSize, wordSize);
            if (wordCount.count (str) == 0)
                return false;
            wordsFound[str]++;
            if (wordsFound[str] > wordCount[str])
                return false;
        }
        return true;
        
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> res;
        if (words.size() == 0)
            return res;
        int totalWords = words.size();
        int wordSize = words[0].size();
        int totalSize = wordSize * totalWords;
        unordered_map <string, int> wordCount;
        for (int i = 0; i < totalWords; i++)
            wordCount[words[i]]++;
        for (int i = 0; i < (int) s.size() - totalSize + 1; i++) {
            if (check (s, wordCount, wordSize, totalWords, i) == true)
                res.push_back (i);
        }
        return res;
    }
};
