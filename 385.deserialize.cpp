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
    NestedInteger deserialize(string s) {
        stack<NestedInteger*> S;
        string num = "";
        for (char &c: s) {
            if (c == '-' || (c >= '0' && c <= '9')) {
                num += c;
            }
            if (c == '[') {
                NestedInteger* cur = new NestedInteger();
                S.push(cur);
            }
            if (c == ',') {
                if (!num.empty()) {
                    S.top()->add(NestedInteger(stoi(num)));
                }
                num = "";
            }
            if (c == ']') {
                if (!num.empty()) {
                    S.top()->add(NestedInteger(stoi(num)));
                }
                NestedInteger* cur = S.top();
                S.pop();
                if (S.empty()) {
                    return *cur;
                } else {
                    S.top()->add(*cur);
                }
                num = "";
            }
        }

        return NestedInteger(stoi(num));
    }
};