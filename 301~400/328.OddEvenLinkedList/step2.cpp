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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* node = head;
      ListNode dummy_head = ListNode(0, head);
      ListNode* prev = &dummy_head;
      
      while (node) {
        if (node->val == val) {
          prev->next = node->next;
        } else {
          prev = node;
        }
        node = node->next;
      }

      return dummy_head.next;
    }
  };
