class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0)
            res += '-';
        long long n = numerator;
        long long d = denominator;
        n = abs (n);
        d = abs (d);
        res += to_string (n / d);
        long long r = n % d;
        if (r == 0) return res;
        res += '.';
        unordered_map<int, int> map;
        while (r) {
            if (map.count (r) != 0) {
                res.insert (map[r], 1, '(');
                res += ')';
                break;
            }
            map[r] = res.size();
            r *= 10;
            res += to_string (r / d);
            r = r % d;
        }
        return res;
    }
};
