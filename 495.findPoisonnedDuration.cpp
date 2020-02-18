class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;
        if (timeSeries.size() == 1) return duration;
        
        int sum = 0;
        int last = timeSeries[0];

        for (int i = 1; i < timeSeries.size(); i++) {
            if (timeSeries[i]>last+duration) {
                sum += duration;
            } else {
                sum += timeSeries[i] - last;
            }
            last = timeSeries[i];
        }
        
        sum += duration;
        return sum;
    }
};