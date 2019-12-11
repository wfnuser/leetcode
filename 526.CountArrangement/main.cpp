class Solution {
public:
    int count = 0;
    vector<int> visited;

    void search(int N, int pos) {
        if (pos > N) count++;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (i%pos == 0 || pos%i == 0)) {
                visited[i] = 1;
                search(N, pos+1);
                visited[i] = 0;
            }
        }
    }

    int countArrangement(int N) {
        this->visited.resize(N+1, 0);
        search(N, 1);
        return count;
    }
};
