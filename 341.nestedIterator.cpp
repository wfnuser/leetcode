/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    int size = 0;
    int cur = 0;
    vector<int> list;

    vector<int> expand(vector<NestedInteger> &nestedList) {
        vector<int> list;
        for (auto l: nestedList) {
            if (l.isInteger()) {
                list.push_back(l.getInteger());
            } else {
                vector<int> next = expand(l.getList());
                list.insert(list.end(), next.begin(), next.end());
            }
        }
        return list;
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        list = expand(nestedList);
        size = list.size();
    }

    int next() {
        return list[cur++];        
    }

    bool hasNext() {
        return cur < size;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */