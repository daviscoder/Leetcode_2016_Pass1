class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 = 0, pos2 = 0, res = INT_MAX;
        bool flag1 = false, flag2 = false;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
                flag1 = true;
            }
            else if (words[i] == word2) {
                pos2 = i;
                flag2 = true;
            }
            if (flag1 && flag2) {
                if (abs(pos1 - pos2) < res)
                    res = abs (pos1 - pos2);
            }
        }
        return res;
    }
};
