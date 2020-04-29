using namespace std;

// Calculate the area of the overlap rectangle directly. Then calculate the final answer.
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int x1 = max(A, E), x2 = min(C, G), y1 = max(B, F), y2 = min(D, H);
        int x = (x1 < x2) ? (x2 - x1) : 0, y = (y1 < y2) ? (y2 - y1) : 0;
        return (C - A) * (D - B) - x * y + (G - E) * (H - F); // first minus then plus, avoid int overflow
    }
};