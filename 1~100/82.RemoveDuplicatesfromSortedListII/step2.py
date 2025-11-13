# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node_to_cnt = {}
        node = head
        while node is not None:
           node_to_cnt[node.val] = node_to_cnt.get(node.val, 0) + 1
           node = node.next

        dummy_head = ListNode()
        dummy_node = dummy_head
        for val, cnt in node_to_cnt.items():
            if cnt == 1:
                dummy_node.next = ListNode(val)
                dummy_node = dummy_node.next

        return dummy_head.next
