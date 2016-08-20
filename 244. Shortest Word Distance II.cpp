class WordDistance {
public:
    unordered_map<string, vector<int>> table;

    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
            table[words[i]].push_back (i);
    }

    int shortest(string word1, string word2) {
        int i = 0, j = 0, res = INT_MAX;
        while (i < table[word1].size() && j < table[word2].size()) {
            res = min (res, abs(table[word1][i] - table[word2][j]));
            table[word1][i] < table[word2][j]? i++ : j++;
        }
        return res;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
