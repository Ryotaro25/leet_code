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
    if (!head) {
      return nullptr;
    }
    int num_nodes = 0;
    ListNode* node = head;
    while (node) {
      num_nodes++;
      node = node->next;
    }

    ListNode dummy_head(0, head);
    ListNode* prev = &dummy_head;
    for (int i = 0; i < num_nodes - n; i++) {
      prev = prev->next;
    }
    // prev->nextは有効な最後のnodeになる場合があるが
    // nullptrを指すことはないので
    // prev->nextが最後の要素の場合、prev->next->nextはnullptr
    prev->next = prev->next->next;
    return dummy_head.next;
  }
};
