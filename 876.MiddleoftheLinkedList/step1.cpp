/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    auto node = head;
    map<int, ListNode*> index_for_node;

    int i = 0;
    while (node) {
      index_for_node[i] = node;
      node = node->next;
      i++;
    }

    node = head;
    while (node) {
      if (node == index_for_node[i / 2]) {
        return node;
      }
      node = node->next;
    }
    return nullptr;
  }
};
