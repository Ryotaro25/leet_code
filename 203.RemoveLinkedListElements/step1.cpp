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

      vector<int> node_vals;
      while (node) {
        if (node->val != val) {
          node_vals.push_back(node->val);
        }
        node = node->next;
      }

      ListNode dummy_head;
      ListNode* dummy_node = &dummy_head;
      for (auto val : node_vals) {
        dummy_node->next = new ListNode(val);
        dummy_node = dummy_node->next;
      }
      return dummy_head.next;
    }
  };
