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
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head) {
        return nullptr;
      }
      int node_cnt = 1;
      ListNode* node = head;
      while (node->next) {
        node = node->next;
        node_cnt++;
      }
      // 1番お尻と先頭を繋ぐ
      node->next = head;

      // nodeを先頭に戻す
      node = head;
      int tail_position = node_cnt - k % node_cnt - 1;
      for (int i = 0; i < tail_position; i++) {
        node = node->next;
      }
      ListNode* new_head = node->next;
      node->next = nullptr;
      return new_head;
    }
  };
