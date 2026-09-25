# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        dummy_head = ListNode()
        dummy_node = dummy_head

        node = head
        reversed = []
        while node:
            reversed.append(node)
            node = node.next

        while reversed:
            dummy_node.next = reversed.pop()
            dummy_node = dummy_node.next

        dummy_node.next = None
        return dummy_head.next
