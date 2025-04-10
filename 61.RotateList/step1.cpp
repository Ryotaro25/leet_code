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
      int node_cnt = 0;
      ListNode* node = head;
      while (node) {
        node_cnt++;
        if (!node->next) {
          node->next = head;
          break;
        }
        node = node->next;
      }

      if (k >= node_cnt) {
        k  %= node_cnt;
      }

      // nodeを先頭に戻す
      node = head;

      for (int i = 0; i < node_cnt - k - 1; i++) {
        node = node->next;
      }
      ListNode* new_head = node->next;
      node->next = nullptr;
      return new_head;
    }
  };
