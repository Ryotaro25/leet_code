/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* copyRandomList(Node* head) {
      if (!head) {
        return nullptr;
      }

      Node* original = head;
      while (original) {
        Node* new_node = new Node(original->val);
        new_node->next = original->next;
        original->next = new_node;
        original =  new_node->next;
      }

      original = head;
      while (original) {
        if (original->random) {
          original->next->random = original->random->next;
        } else {
          original->next->random = nullptr;
        }
        original = original->next->next;
      }

      Node* old_list = head;
      Node* new_list = head->next;
      Node* new_list_head = new_list;
      while (old_list) {
        old_list->next = old_list->next->next;
        if (new_list->next) {
          new_list->next = new_list->next->next;
        } else {
          new_list->next = nullptr;
        }
        old_list = old_list->next;
        new_list = new_list->next;
      }

      return new_list_head;
    }
  };
