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
    ListNode* insertionSortList(ListNode* head) {
      ListNode dummy_head;
      dummy_head.next = nullptr;
      ListNode* node = head;
      while (node) {
        ListNode* before_inserting_node = &dummy_head;
        while (before_inserting_node->next && before_inserting_node->next->val <= node->val) {
          before_inserting_node = before_inserting_node->next;
        }

        ListNode* next_precess_node = node->next;
        node->next = before_inserting_node->next;
        before_inserting_node->next = node;
        node = next_precess_node;
      }

      return dummy_head.next;
    }
  };
