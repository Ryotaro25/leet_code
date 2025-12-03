# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode()
        dummy_node = dummy_head
        carry = 0
        while l1 is not None or l2 is not None or carry != 0:
            sum_of_two_num = carry
            
            if l1 is not None:
                sum_of_two_num += l1.val
                l1 = l1.next

            if l2 is not None:
                sum_of_two_num += l2.val
                l2 = l2.next

            carry = sum_of_two_num // 10
            digit = sum_of_two_num % 10
            dummy_node.next = ListNode(digit)
            dummy_node = dummy_node.next

        return dummy_head.next
