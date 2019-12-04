class Solution
{
public:
    vector<int> cheapestJump(vector<int> &A, int B)
    {
        int size = A.size();
        int before[1001] = {0};
        int cost[1001] = {0};
        int count = 0;
        vector<int> pathR;

        if (A[size-1] == -1) return pathR;

        for (int i = size - 1; i >= 0; i--) {
            if (count >= B) return pathR;
            if (A[i] == -1) count++;
            if (A[i] != -1) count = 0;
        }

        for (int i = size - 1; i >= 0; i--)
        {
            if (A[i] == -1)
                continue;
            int start = (i + B) <= size - 1 ? (i + B) : size - 1;
            int min = 2147483647;
            if (i == size - 1) min = 0;
            int beforeNode = -1;
            for (int j = start; j > i; j--)
            {
                if (A[j] == -1)
                    continue;
                if (cost[j] <= min)
                {
                    min = cost[j];
                    beforeNode = j;
                }
            }
            cost[i] = min + A[i];
            before[i] = beforeNode;
        }
        int cur = 0;
        while (cur != -1)
        {
            pathR.push_back(cur+1);
            cur = before[cur];
        }

        return pathR;
    }
};
