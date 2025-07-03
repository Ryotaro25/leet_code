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

    map<Node*, Node*> original_to_clone;
    original_to_clone[node] = new Node(node->val);
    queue<Node*> traversing_nodes;
    traversing_nodes.push(node);
    while (!traversing_nodes.empty()) {
      Node* current_node = traversing_nodes.front();
      traversing_nodes.pop();

      for (auto neighbor: current_node->neighbors) {
        if (!original_to_clone.contains(neighbor)) {
          original_to_clone[neighbor] = new Node(neighbor->val);
          traversing_nodes.push(neighbor);
        }
        original_to_clone[current_node]->neighbors.push_back(original_to_clone[neighbor]);
      }
    }

    return original_to_clone[node];
  }
};
