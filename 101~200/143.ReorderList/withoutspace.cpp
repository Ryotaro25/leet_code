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
    if (!head) {
      return;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // reverse the second node, which is half 
    ListNode* prev = nullptr;
    ListNode* node = slow;
    while (node) {
      ListNode* tmp_next = node->next;
      node->next = prev;
      prev = node;
      node = tmp_next;
    }

    ListNode* first = head;
    ListNode* second = prev;
    while (second->next) {
      ListNode* tmp_first_next = first->next;
      first->next = second;
      first = tmp_first_next;

      ListNode* tmp_second_next = second->next;
      second->next = first;
      second = tmp_second_next;
    }
  }
};
