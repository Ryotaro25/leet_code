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
    map<int, ListNode*> index_to_node;
    ListNode* node = head;
    int i = 0;
    while (node) {
      index_to_node[i] = node;
      i++;
      node = node->next;
    }

    int left = 0;
    int right = index_to_node.size() - 1;
    bool is_from_left = true;
    node = head;
    while (left <= right) {
      if (is_from_left) {
        node->next = index_to_node[left];
        left++;
      } else {
        node->next = index_to_node[right];
        right--;
      }
      is_from_left = !is_from_left;
      node = node->next;
    }
    node->next = nullptr;
  }
};
