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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* node = head;
    map<int, ListNode*> val_to_node;
    while (node) {
      val_to_node[node->val] = node;
      node = node->next;
    }

    ListNode dummy_head;
    ListNode* dummy_node = &dummy_head;
    for (auto [val, node] : val_to_node) {
      dummy_node->next = node;
      dummy_node = dummy_node->next;
    }
    dummy_node->next = nullptr;
    return dummy_head.next;
  }
};
