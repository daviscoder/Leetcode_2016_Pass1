class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0)
            return "";
        int tCnt[256] = {0};
        int sCnt[256] = {0};
        queue <int> myQueue;
        int tLength = t.length(), start = -1, end = s.length(), hasFound = 0;
        for (int i = 0; i < t.length(); i++)
            tCnt[t[i]]++;
        for (int i = 0; i < s.length(); i++) {
            if (tCnt[s[i]] != 0) {
                myQueue.push (i);
                sCnt[s[i]]++;
                if (sCnt[s[i]] <= tCnt[s[i]])
                    hasFound++;
                if (hasFound == (int)t.length()) {
                    int tmp;
                    do {
                        tmp = myQueue.front();
                        myQueue.pop();
                        sCnt[s[tmp]]--;
                    } while (sCnt[s[tmp]] >= tCnt[s[tmp]]);
                    if (end - start > i - tmp) {
                        start = tmp;
                        end = i;
                    }
                    hasFound--;
                }
            }
        }
        return start == -1? "" : s.substr (start, end - start + 1);
    }
};
