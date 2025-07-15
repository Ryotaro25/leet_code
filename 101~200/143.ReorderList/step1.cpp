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
  void reorderList(ListNode* head) {
    map<int, ListNode*> index_to_node;
    ListNode* node = head;
    int i = 0;
    while (node) {
      index_to_node[i] = node;
      i++;
      node = node->next;
    }

    int left = 0;
    int right = index_to_node.size() - 1;
    bool is_from_left = true;
    ListNode dummy_head;
    ListNode* dummy_node = &dummy_head;
    while (left <= right) {
      if (is_from_left) {
        dummy_node->next = index_to_node[left];
        left++;
      } else {
        dummy_node->next = index_to_node[right];
        right--;
      }
      is_from_left = !is_from_left;
      dummy_node = dummy_node->next;
    }
    dummy_node->next = nullptr;
    head = dummy_head.next;
  }
};
