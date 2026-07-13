# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy_head: ListNode = ListNode()
        dummy_node: ListNode = dummy_head
        carry = 0

        while l1 is not None or l2 is not None or carry != 0:
            sum_number: int = carry

            if l1 is not None:
                sum_number += l1.val
                l1 = l1.next

            if l2 is not None:
                sum_number += l2.val
                l2 = l2.next

            digit: int = sum_number % 10
            carry: int = sum_number // 10

            dummy_node.next = ListNode(digit)
            dummy_node = dummy_node.next

        return dummy_head.next
