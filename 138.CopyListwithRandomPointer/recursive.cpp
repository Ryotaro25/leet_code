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
      return BuildClonedNodeList(head, original_to_cloned);
    }

  private:
    Node* BuildClonedNodeList(Node* node, map<Node*, Node*>& original_to_cloned) {
      if (!node) {
        return nullptr;
      }
      if (original_to_cloned.contains(node)) {
        return original_to_cloned[node];
      }

      Node* new_node = new Node(node->val);
      original_to_cloned[node] = new_node;

      new_node->next = BuildClonedNodeList(node->next, original_to_cloned);
      new_node->random = BuildClonedNodeList(node->random, original_to_cloned);
      return new_node;
    }
  };
