class TrieNode {
public:
    bool isKey;
    TrieNode * children[26];
    // Initialize your data structure here.
    TrieNode() {
        isKey = false;
        memset (children, 0, sizeof (TrieNode*) * 26);
    }
};

class Trie {
public:
    Trie() {
        this->root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p->children[word[i] - 'a'] == NULL) {
                p->children[word[i] - 'a'] = new TrieNode ();
            }
            p = p->children[word[i] - 'a'];
        }
        p->isKey = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            if (p == NULL)
                break;
            else
                p = p->children[word[i] - 'a'];
        }
        if (p == NULL)
            return false;
        return p->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p == NULL) {
                return false;
            }
            p = p->children[prefix[i] - 'a'];
        }
        if (p == NULL)
            return false;
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
