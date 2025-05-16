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
  ListNode* middleNode(ListNode* head) {
    auto node = head;
    vector<ListNode*> nodes;
    while (node) {
      nodes.push_back(node);
      node = node->next;
    }
    return nodes[nodes.size() / 2];
  }
};
