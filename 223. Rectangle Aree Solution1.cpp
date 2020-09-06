class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        using LL = long long;
        LL X = max(0ll, min(C, G) + 0ll - max(A, E));
        LL Y = max(0ll, min(D, H) + 0ll - max(B, F));
        return (C - A) * (D - B) - X * Y + (G - E) * (H - F);
    }
};
