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
      int node_size = GetNodeSize(head);
      int target_index = node_size - n;
      if (node_size == 1) {
        return nullptr;
      }

      
      ListNode* target_node = GetNode(head, target_index);
      if (target_index == 0) {
        head->next = target_node->next;
        return head->next;
      }

      ListNode* prev_node = GetNode(head, target_index - 1);
      prev_node->next = target_node->next;

      return head;
    }
  
  private:
    ListNode* GetNode(ListNode* head, int target_index) {
      int index = 0;
      ListNode* node = head;
      while (node && index < target_index) {
        node = node->next;
        index++;
      }

      if (!node) {
        return nullptr;
      }

      return node;
    }

  int GetNodeSize(ListNode* head) {
    ListNode* node = head;
    int size = 0;

    while (node) {
      node = node->next;
      size++;
    }
    return size;
  }
  };
