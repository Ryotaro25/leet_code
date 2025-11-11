# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        seen_vals = set()
        dummy_head = ListNode()
        dummy_node = dummy_head

        while node is not None:
            if node.val not in seen_vals:
                seen_vals.add(node.val)

                dummy_node.next = ListNode(node.val)
                dummy_node = dummy_node.next
            node = node.next
        return dummy_head.next
