class ZigzagIterator {
public:
    vector<int> vv1;
    vector<int> vv2;
    int index1;
    int index2;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        vv1 = v1;
        vv2 = v2;
        index1 = 0;
        index2 = 0;
    }

    int next() {
        if (!hasNext()) return 0;

        if (index1 >= vv1.size()) {
            return vv2[index2++];
        }

        if (index2 >= vv2.size()) {
            return vv1[index1++];
        }

        if (index1 > index2) {
            return vv2[index2++];
        } else {
            return vv1[index1++];
        }
    }

    bool hasNext() {
        return !(index1>=vv1.size() && index2>=vv2.size());
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */