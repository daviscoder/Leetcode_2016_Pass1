class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool my_map[256] = {false};
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (my_map[s[i]] == true) {
                my_map[s[i]] = false;
                cnt--;
            }
            else {
                my_map[s[i]] = true;
                cnt++;
            }
        }
        return cnt <= 1;
    }
};
