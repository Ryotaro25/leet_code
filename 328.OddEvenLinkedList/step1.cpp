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
    ListNode* oddEvenList(ListNode* head) {
      ListNode odd_head;
      ListNode* odd_node = &odd_head;

      ListNode even_head;
      ListNode* even_node = &even_head;

      ListNode* node = head;
      int index = 1;
      while (node) {
        if (index % 2 != 0) {
          odd_node->next = node;
          odd_node = odd_node->next;
        } else {
          even_node->next = node;
          even_node = even_node->next;
        }
        node = node->next;
        index++;
      }
      even_node->next = nullptr;
      odd_node->next = even_head.next;

      return odd_head.next;
    }
  };
