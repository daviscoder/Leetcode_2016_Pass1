class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        if (C <= E || A >= G || B >= H || D <= F) return sum;
        return sum - (min (G, C) - max (A, E)) * (min(D, H) - max(B, F));
    }
};
