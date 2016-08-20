class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0)
            return 0;
        unordered_map <char, int> myMap = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0, prev = myMap[s[0]];
        for (int i = 1; i < (int)s.length(); i++) {
            if (prev < myMap[s[i]])
                res = res - prev;
            else
                res += prev;
            prev = myMap[s[i]];
        }
        res += myMap[s[s.length() - 1]];
        return res;
    }
};
