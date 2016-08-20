class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        int size = s.size();
        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;
        for (int i = 0; i < size; i++) {
            if (sTot.count (s[i])) {
                if (sTot[s[i]] != t[i])
                    return false;
            }
            if (tTos.count (t[i])) {
                if (tTos[t[i]] != s[i])
                    return false;
            }
            sTot[s[i]] = t[i];
            tTos[t[i]] = s[i];
        }
        return true;
    }
};
