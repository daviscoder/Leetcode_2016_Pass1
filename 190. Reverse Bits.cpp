class Solution {
public:
    int swapbits (uint32_t n, int i, int j) {
        int a = (n >> i) & 1;
        int b = (n >> j) & 1;
        if (a ^ b)
            return n ^ (1 << i | 1 << j);
        return n;
    }
    
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++)
            n = swapbits (n, i, 32 - i - 1);
        return n;
    }
};
