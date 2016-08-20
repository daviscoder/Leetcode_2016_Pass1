class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long pos1 = INT_MAX, pos2 = INT_MIN, res = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
            }
            if (words[i] == word2) {
                if (word1 == word2)
                    pos1 = pos2;
                pos2 = i;
            }
            if (abs(pos1 - pos2) < res)
                res = abs (pos1 - pos2);
        }
        return res;
    }
};
