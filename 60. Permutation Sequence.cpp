class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string seq (n, 0);
        int fac = 1;
        for (int i = 1; i <= n; i++) {
            fac *= i;
            seq[i - 1] = i + '0';
        }
        k--; // !!!!重要！！！
        for (int i = 0; i < n; i++) {
            fac /= (n - i);
            int cur = k / fac;
            res.push_back (seq[cur]);
            seq.erase (seq.begin() + cur);
            k = k % fac;
        }
        return res;
    }
};
