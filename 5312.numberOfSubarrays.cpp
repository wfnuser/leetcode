class Solution {
public:    
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        long sumK = 0;
        long sumThreshold = (long)k * threshold;
        for (int i = 0; i < k-1; i++) {
            sumK += arr[i];
        }
        
        for (int i = k-1; i < arr.size(); i++) {
            sumK += arr[i];
            // cout << "from " << i - k + 1 << " to " << i << endl;
            // cout << sumK << endl;
            if (sumK >= sumThreshold) ans++;
            sumK -= arr[i - k + 1];
        }
        
        return ans;
    }
};