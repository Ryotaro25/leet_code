/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      auto first_node = headA;
      auto second_node = headB;

      while (first_node != second_node) {
        if (!first_node) {
          first_node = headB;
        } else {
          first_node = first_node->next;
        }
        if (!second_node) {
          second_node = headA;
        } else {
          second_node = second_node->next;
        }
      }

      return first_node;
    }
  };
  