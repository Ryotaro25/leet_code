/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
  public:
    Node* flatten(Node* head) {
      if (!head) {
        return nullptr;
      }
      vector<Node*> all_nodes;
      stack<Node*> next_travese_nodes;
      next_travese_nodes.push(head);

      while (!next_travese_nodes.empty()) {
        Node* current = next_travese_nodes.top();
        next_travese_nodes.pop();
        all_nodes.push_back(current);

        if (current->next) {
          next_travese_nodes.push(current->next);
        }
        if (current->child) {
          next_travese_nodes.push(current->child);
        }
      }

      for (int i = 0; i < all_nodes.size() - 1; i++) {
        all_nodes[i]->next = all_nodes[i + 1];
        all_nodes[i + 1]->prev = all_nodes[i];
        all_nodes[i]->child = nullptr;
      }
      return all_nodes[0];
    }
  };
