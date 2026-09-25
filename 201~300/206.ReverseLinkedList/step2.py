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
        node_stack = []
        while node:
            node_stack.append(node)
            node = node.next

        while node_stack:
            dummy_node.next = node_stack.pop()
            dummy_node = dummy_node.next

        dummy_node.next = None
        return dummy_head.next
