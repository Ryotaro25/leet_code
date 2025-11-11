# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        dummy_node = dummy_head
        seen_values = set()

        node = head
        while node is not None:
            if node.val not in seen_values:
                dummy_node.next = ListNode(node.val)
                seen_values.add(node.val)
                dummy_node = dummy_node.next
            node = node.next
        return dummy_head.next
