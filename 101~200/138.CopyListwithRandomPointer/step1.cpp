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

      map<Node*, Node*> original_to_cloned;
      Node* node = head;
      while (node) {
        original_to_cloned[node] = new Node(node->val);
        node = node->next;
      }

      node = head;
      while (node) {
        original_to_cloned[node]->next = original_to_cloned[node->next];
        original_to_cloned[node]->random = original_to_cloned[node->random];
        node = node->next;
      }

      return original_to_cloned[head];
    }
  };
