class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if (n == 1) return numbers[0];

        int left = 0;
        int right = n - 1;
        
        while(left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] == numbers[right]) {
                right--;
            } else {
                right = mid;
            }
        }

        return numbers[right];
    }
};