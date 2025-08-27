/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return nullptr;
    }
    map<Node*, Node*> node_to_clone;
    return GenerateClone(node, node_to_clone);
  }

private:
  Node* GenerateClone(Node* node, map<Node*, Node*>& node_to_clone) {
    if (!node) {
      return nullptr;
    }
    if (node_to_clone.contains(node)) {
      return node_to_clone[node];
    }
    Node* cloned = new Node(node->val);
    node_to_clone[node] = cloned;
    for (auto neighbor : node->neighbors) {
      cloned->neighbors.push_back(GenerateClone(neighbor, node_to_clone));
    }
    return cloned;
  }
};
