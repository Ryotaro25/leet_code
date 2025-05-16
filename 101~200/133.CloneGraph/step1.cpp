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
      return CreateClone(node);
    }

  private:
    map<Node*, Node*> original_to_cloned;
    Node* CreateClone(Node* node) {
      if (!node) {
        return nullptr;
      }
      if (original_to_cloned.contains(node)) {
        return original_to_cloned[node];
      }
      Node* cloned = new Node(node->val);
      original_to_cloned[node] = cloned;
      for (auto neighbor_node : node->neighbors) {
        Node* cloned_neighbor = CreateClone(neighbor_node);
        cloned->neighbors.push_back(cloned_neighbor);
      }
      return cloned;
    }
  };
