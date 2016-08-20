class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1)
            return true;
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (isalpha (s[l]) == false && isdigit(s[l]) == false && l < r)
                l++;
            while (isalpha (s[r]) == false && isdigit(s[r]) == false && l < r)
                r--;
            if (isalpha (s[l]) && isalpha (s[r]) && tolower (s[l]) == tolower (s[r])) {
                l++;
                r--;
            }
            else if (s[l] == s[r]) {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
