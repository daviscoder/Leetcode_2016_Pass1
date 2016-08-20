class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq (256, 0);
        if (s.size() <= 0 || t.size() <= 0)
            return true;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
            freq[s[i]]++;
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]--;
            if (freq[t[i]] == -1)
                return false;
        }
        return true;
    }
};
