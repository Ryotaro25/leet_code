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
    ListNode* insertionSortList(ListNode* head) {
      if (!head) {
        return nullptr;
      }
      vector<ListNode*> nodes;
      ListNode* node = head;
      while (node) {
        nodes.push_back(node);
        node = node->next;
      }

      for (int i = 1; i < nodes.size(); i++) {
        ListNode* inserting_node = nodes[i];
        int j = i - 1;
        while (j >= 0 && nodes[j]->val > inserting_node->val) {
          // あきを作るために要素を右にずらす
          nodes[j + 1] = nodes[j];
          j--;
        }
        nodes[j + 1] = inserting_node;
      }

      ListNode dummy_head;
      ListNode* dummy = &dummy_head;
      for (auto sorted_node : nodes) {
        dummy->next = sorted_node;
        dummy = dummy->next;
      }
      dummy->next = nullptr;
      return dummy_head.next;
    }
  };
