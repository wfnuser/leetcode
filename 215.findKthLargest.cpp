class Solution {
public:

    void insert(vector<int>& heap, int num) {
        heap[0] = num;
        sift_down(heap, 0);
    }

    void sift_down(vector<int>& heap, int index) {
        int num = heap[index];
        int left, right;
        int size = heap.size();
        if (index*2+1 >= size) return;
        left = heap[index*2+1];
        if (index*2+2 == size) {
            if (left <= num) {
                heap[index] = heap[index*2+1];
                heap[index*2+1] = num;
            }
            return;
        }
        right = heap[index*2+2];
        if (left < right) {
            if (num >= left) {
                heap[index] = heap[index*2+1];
                heap[index*2+1] = num;
                sift_down(heap, index*2+1);
            }
        } else {
            if (num >= right) {
                heap[index] = heap[index*2+2];
                heap[index*2+2] = num;
                sift_down(heap, index*2+2);
            }
        }
        return;
    }


    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(k, INT_MIN);

        for (auto num: nums) {
            if (num >= heap[0]) {
                insert(heap, num);
            }
        }

        return heap[0];
    }
};