/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int sum = 0;
    int d = 0;
    void cal(vector<NestedInteger>& nestedList, int depth) {
        for (auto l: nestedList) {
            if (l.isInteger()) {
                sum += l.getInteger()*(d-depth);
            } else {
                cal(l.getList(), depth+1);
            }
        }
    }

    int calDepth(vector<NestedInteger>& nestedList) {
        int d = 1;
        for (auto l: nestedList) {
            if (l.isInteger()) {
                d = max(d, 1);
            } else {
                d = max(calDepth(l.getList())+1, d);
            }
        }
        return d;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        d = calDepth(nestedList);
        cal(nestedList, 0);
        return sum;
    }
};