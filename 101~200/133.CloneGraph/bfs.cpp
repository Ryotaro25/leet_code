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

      map<Node*, Node*> cloned_node_so_far;
      cloned_node_so_far[node] = new Node(node->val);

      queue<Node*> traversing;
      traversing.push(node);
      while (!traversing.empty()) {
        Node* current_node = traversing.front();
        traversing.pop();
        for (auto neighbor : current_node->neighbors) {
          if (!cloned_node_so_far.contains(neighbor)) {
            cloned_node_so_far[neighbor] = new Node(neighbor->val);
            traversing.push(neighbor);
          }
          cloned_node_so_far[current_node]->neighbors.push_back(cloned_node_so_far[neighbor]);
        }
      }

      return cloned_node_so_far[node];
    }
  };
