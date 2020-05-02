/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string data = "";

        if (root == NULL) return data;

        queue<Node*> Q;
        Q.push(root);

        while(!Q.empty()) {
            Node* cur = Q.front();
            Q.pop();

            data += to_string(cur->val);
            data += ",";
            data += to_string(cur->children.size());
            data += ",";

            for (auto child: cur->children) {
                Q.push(child);
            }
        }

        return data;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return NULL;

        string tmp = "";
        int i = 0;

        queue<pair<int, int>> Q;

        while(i < data.size()) {
            if (data[i] == ',') {
                i++;
                int val = stoi(tmp);
                tmp = "";
                while(i < data.size()) {
                    if (data[i] == ',') {
                        int cnt = stoi(tmp);
                        Q.push(make_pair(val, cnt));
                        tmp = "";
                        i++;
                        break;
                    } else {
                        tmp += data[i];
                        i++;
                    }
                }
                tmp = "";
            } else {
                tmp += data[i];
                i++;
            }
        }

        queue<Node*> nodes;
        pair<int, int> p = Q.front();
        Q.pop();
        vector<Node*> v = vector<Node*>(p.second, NULL);
        Node* root = new Node(p.first, v);
        nodes.push(root);


        while (!Q.empty()) {
            Node* cur = nodes.front();
            nodes.pop();
            for (int i = 0; i < cur->children.size(); i++) {
                p = Q.front();
                Q.pop();
                v = vector<Node*>(p.second, NULL);
                Node* next = new Node(p.first, v);
                nodes.push(next);
                cur->children[i] = next;
            }
        }


        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));