# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        dummy_head.next = head

        prev_node = dummy_head
        curr_node = head
        while curr_node is not None:
            if curr_node.next is not None and curr_node.val == curr_node.next.val:
                while curr_node.next is not None and curr_node.val == curr_node.next.val:
                    curr_node = curr_node.next
                prev_node.next = curr_node.next
            else:
                prev_node = prev_node.next
            curr_node = curr_node.next
        return dummy_head.next
