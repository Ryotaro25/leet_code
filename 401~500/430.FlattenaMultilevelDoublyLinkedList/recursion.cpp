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
      Node dummy_head;
      Node* dummy_node = &dummy_head;
      Node* tail = FlatNode(dummy_node, head);
      dummy_head.next->prev = nullptr;
      return dummy_head.next;
    }

    Node* FlatNode(Node* prev_node, Node* curr_node) {
      if (!curr_node) {
        return prev_node;
      }
      curr_node->prev = prev_node;
      prev_node->next = curr_node;

      Node* temp_next = curr_node->next;
      Node* tail = FlatNode(curr_node, curr_node->child);
      curr_node->child = nullptr;

      return FlatNode(tail, temp_next);
    }
  };
