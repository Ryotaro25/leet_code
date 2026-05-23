# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node: ListNode = head
        visited_nodes: set[ListNode] = set()
        while node is not None:
            if node in visited_nodes:
                return node
            visited_nodes.add(node)
            node = node.next
        return None
