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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    map<int, vector<ListNode*>> val_to_nodes;
    for (auto node : lists) {
      while (node) {
        val_to_nodes[node->val].push_back(node);
        node = node->next;
      }
    }

    ListNode dummy_head;
    ListNode* dummy_node = &dummy_head;
    for (auto [val, nodes] : val_to_nodes) {
      for (auto node : nodes) {
        dummy_node->next = node;
        dummy_node = dummy_node->next;
      }
    }
    dummy_node->next = nullptr;
    return dummy_head.next;
  }
};
