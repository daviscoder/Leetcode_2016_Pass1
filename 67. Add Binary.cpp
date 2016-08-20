class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() <= 0) return b;
        if (b.size() <= 0) return a;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0, i;
        string res;
        for (i = 0; i < a.length() || i < b.length() || carry; i++) {
            char current = carry;
            if (i < a.length())
                current += a[i] - '0';
            if (i < b.length())
                current += b[i] - '0';
            res.push_back ((char)(current % 2 + '0'));
            carry = current / 2;
        }
        reverse (res.begin(), res.end());
        return res;
        
    }
};
