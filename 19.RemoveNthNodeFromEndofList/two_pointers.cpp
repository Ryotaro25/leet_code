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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode dummy_head;
      dummy_head.next = head;
      ListNode* first_node = &dummy_head;
      ListNode* second_node = &dummy_head;

      for (int i = 0; i <= n; i++) {
        first_node = first_node->next;
      }

      while (first_node) {
        first_node = first_node->next;
        second_node = second_node->next;
      }
      second_node->next = second_node->next->next;
      return dummy_head.next;
    }
  };
