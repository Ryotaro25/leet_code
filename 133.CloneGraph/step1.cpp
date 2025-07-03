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
    map<Node*, Node*> visited_to_cloned;
    return CloneNode(node, visited_to_cloned);
  }

private:
  Node* CloneNode(Node* node, map<Node*, Node*>& visited_to_cloned) {
    if (!node) {
      return nullptr;
    }
    if (visited_to_cloned.contains(node)) {
      return visited_to_cloned[node];
    }
    Node* cloned = new Node(node->val);
    visited_to_cloned[node] = cloned;
    for (auto neighbor : node->neighbors) {
      cloned->neighbors.push_back(CloneNode(neighbor, visited_to_cloned));
    }
    return cloned;
  }
};
