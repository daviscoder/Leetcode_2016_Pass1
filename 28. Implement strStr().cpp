class Solution {
public:
    vector <int> getNext (string s) {
        vector <int> res (s.size(), -1);
        int k = -1; // index of prefix.
        int j = 0; // index of postfix
        while (j < s.size() - 1) {
            if (k == -1 || s[k] == s[j]) {
                k++;
                j++;
                res[j] = k;
            }
            else {
                k = res[k];
            }
        }
//        for (int i = 0; i < res.size(); i++)
//            cout << res[i] << " ";
        return res;
    }
    
    int strStr(string haystack, string needle) {
        if (needle.length() <= 0)
            return 0;
        if (haystack.length() <= 0)
            return -1;
        vector <int> next = getNext (needle);
        int i = 0, j = 0;
        while (i < (int) haystack.length() && j < (int)needle.length()) {
            cout << i << "\t" << j << "\t" << haystack.length() << "\t" << needle.length() <<  endl;
            if (j == -1 || haystack[i] == needle[j]) {
                j++;
                i++;
            }
            else {
                j = next[j];
                cout << j << endl;
            }
        }
        return j == needle.length()? i - j : -1;
    }
};
