class NumArray {
public:
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        tree = vector<int>(nums.size()+1, 0);
        int idx=1;
        for(auto num:nums) add(idx++, num);   
    }
    
    int lowbit(int x) {
        return x&-x;
    }

    void add(int i, int val) {
        if (i>=tree.size()) return;
        tree[i] += val;
        add(i+lowbit(i), val);
    }
    
    int sum(int i){
        return i>0 ? tree[i]+sum(i-lowbit(i)) : 0;
    }

    void update(int i, int val) {
        int idxVal = sum(i+1)-sum(i);
        add(i+1, val-idxVal);
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */