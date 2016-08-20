// http://www.cnblogs.com/grandyang/p/4431646.html
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int num = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            num++;
        }
        return m << num;
        
    }
};
