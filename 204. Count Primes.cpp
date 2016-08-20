class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        vector <bool> isPrime (n, true);
        int cnt = 0;
        for (int i = 2; i * i < n; i++) {
            for (int j = i * 2; j < n; j += i)
                isPrime [j] = false;
        }
        for (int i = 2; i < n; i++) 
            if (isPrime[i] == true)
                cnt++;
        return cnt;
    }
};
