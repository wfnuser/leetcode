class CustomStack {
   public:
    int maxSize = 0;
    stack<int> S;
    vector<int> V;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        this->V = vector<int>(maxSize, 0);
    }

    void push(int x) {
        if (S.size() >= maxSize) return;
        S.push(x);
    }

    int pop() {
        if (S.size() == 0) return -1;

        int delta = V[S.size() - 1];
        V[S.size() - 1] = 0;
        int top = S.top();
        S.pop();

        return delta + top;
    }

    void increment(int k, int val) {
        int size = S.size();
        size = min(k, size);
        for (int i = 0; i < size; i++) {
            V[i] += val;
        }
    }
};
