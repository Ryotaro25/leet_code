/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
  public:
    Node* insert(Node* head, int insertVal) {
      if (!head) {
        Node* new_node = new Node(insertVal, nullptr);
        new_node->next = new_node;
        return new_node;
      }

      Node* current_node = head->next;
      Node* prev_node = head;
      while (true) {
        if (prev_node->val <= insertVal && current_node->val >= insertVal) {
          break;
        }

        if (prev_node->val > current_node->val) {
          if (prev_node->val <= insertVal || current_node->val >= insertVal) {
            break;
          }
        }
        current_node = current_node->next;
        prev_node = prev_node->next;
        
        // 一周したら判定
        if (prev_node == head) {
          break;
        }
      }

      Node* new_node = new Node(insertVal, current_node);
      prev_node->next = new_node;
      return head;
    }
  };
