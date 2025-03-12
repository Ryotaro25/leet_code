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
    bool isPalindrome(ListNode* head) {
      int size = 0;
      auto node = head;
      while (node) {
        size++;
        node = node->next;
      }
      if (size == 1) {
        return true;
      }

      node = head;
      int cnt = 0;
      stack<int> vals;
      while (cnt < size / 2) {
        vals.push(node->val);
        cnt++;
        node = node->next;
      }

      if (size % 2 != 0) {
        if (node->next) {
          node = node->next;
        } else {
          return false;
        }
      }

      while (node) {
        if (vals.top() != node->val) {
          return false;
        }
        node = node->next;
        vals.pop();
      }
      return true;
    }
  };
