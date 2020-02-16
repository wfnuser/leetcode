class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap = 0;

        if (!(E>=C || H <=B || F >= D || G <= A)) {
            overlap = (min(C,G)-max(A,E))*(min(H,D)-max(B,F));
        }

        return (D-B)*(C-A)-overlap+(H-F)*(G-E);
    }
};