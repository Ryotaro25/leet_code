# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        nodes_and_level = []
        nodes_and_level.append((root, 1))
        max_depth = 0
        while nodes_and_level:
            node, level = nodes_and_level.pop(0)
            max_depth = level
            if node.left is not None:
                nodes_and_level.append((node.left, level + 1))
            if node.right is not None:
                nodes_and_level.append((node.right, level + 1))
        return max_depth
