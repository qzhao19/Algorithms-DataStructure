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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> node_queue;

        if (root != NULL) {
            node_queue.push(root);
        }

        while (!node_queue.empty()) {
            int q_size = node_queue.size();
            vector<int> tmp;
            while (q_size--) {
                for (auto child : node_queue.front() -> children) {
                    if (child != NULL) {
                        node_queue.push(child);
                    }
                }
                tmp.push_back(node_queue.front() -> val);
                node_queue.pop();
            }
            result.push_back(tmp);
        }

        return result;
    }
};