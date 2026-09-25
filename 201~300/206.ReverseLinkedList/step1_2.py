# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode | None) -> ListNode | None:
        node = head
        dummy_node = None
        while node:
            temp = node.next
            node.next = dummy_node
            dummy_node = node
            node = temp
        return dummy_node
