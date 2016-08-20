class Solution {
public:
    int numDecodings(string s) {
        if (s.size() <= 0)
            return 0;
        int current, prev = 1, prevPrev = 0, prevNum = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            int num = s[i] - '0';
            if (num > 0)
                current = prev;
            else
                current = 0;
            if (prevNum == 1 || prevNum == 2 && num <= 6)
                current += prevPrev;
            prevPrev = prev;
            prev = current;
            prevNum = num;
        }
        return current;
    }
};
