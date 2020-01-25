/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};
*/
class Solution {
public:
    unordered_map<int, Node*> nodes;

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (nodes[node->val]) return nodes[node->val];
        Node* n = new Node();
        n->val = node->val;
        nodes[n->val] = n;

        vector<Node*> cloneNeighbors;
        for (auto neighbor: node->neighbors) {
            cloneNeighbors.push_back(cloneGraph(neighbor));
        }
        n->neighbors = cloneNeighbors;
 
        return n;
    }
};