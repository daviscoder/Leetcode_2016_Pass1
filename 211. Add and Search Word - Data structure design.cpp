class TrieNode {
public:
    bool isEnd;
    TrieNode *children[26];
    TrieNode () : isEnd (false) {
        memset (children, 0, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
private:
    TrieNode * root;
public:
    WordDictionary () {
        this->root = new TrieNode ();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (cur->children[index] == NULL)
                cur->children[index] = new TrieNode ();
            cur = cur->children[index];
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search (word, word.size(), 0, root);
    }
    
    bool search (string& word, int n, int pos, TrieNode * cur) {
        if (cur == NULL) return false;
        if (pos == n) return cur->isEnd;
        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (search (word, n, pos + 1, cur->children[i]))
                    return true;
            }
        }
        else {
            int index = word[pos] - 'a';
            return search (word, n, pos + 1, cur->children[index]);
        }
        return false;
    }
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
