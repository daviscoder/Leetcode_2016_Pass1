class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector <int> twos (1, 1), threes (1, 1), fives (1, 1);
        int a = 0, b = 0, c = 0, res;
        for (int i = 0; i < n; i++) {
            res = min (twos[a], min (threes[b], fives[c]));
            if (res == twos[a]) 
                a++;
            if (res == threes[b])
                b++;
            if (res == fives[c])
                c++;
            twos.push_back (res * 2);
            threes.push_back (res * 3);
            fives.push_back (res * 5);
        }
        return res;
    }
};
