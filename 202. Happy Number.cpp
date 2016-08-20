class Solution {
public:
    int getNext (int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> mySet;
        while (1) {
            if (n == 1)
                return true;
            if (mySet.count (n))
                return false;
            mySet.insert (n);
            n = getNext (n);
        }
        return false;
    }
};
