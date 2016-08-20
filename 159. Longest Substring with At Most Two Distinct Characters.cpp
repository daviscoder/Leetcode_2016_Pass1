// http://www.jiuzhang.com/solutions/longest-substring-with-at-most-k-distinct-characters/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, k = 2, res = 0, cnt = 0;
        int myMap[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (myMap[s[i]] == 0)
                cnt++;
            myMap[s[i]]++;
            while (cnt > k) {
                myMap[s[start]]--;
                if (myMap[s[start]] == 0)
                    cnt--;
                start++;

            }
            res = max (i - start + 1, res);
        }
        return res;
    }
};
