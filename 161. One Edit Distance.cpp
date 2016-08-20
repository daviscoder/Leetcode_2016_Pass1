class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        for (int i = 0; i < s.size() && i < t.size(); i++)
            if (s[i] != t[i])
                return s.substr(i + 1) == t.substr(i + 1) || s.substr(i) == t.substr(i + 1) || s.substr(i + 1) == t.substr(i);
        return abs ((int)s.size() - (int)t.size()) == 1;
    }
};
