/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int kthSmallest(TreeNode* node, int k) {
    stack<TreeNode*> traversal_nodes;
    int count = k;
    while (node || !traversal_nodes.empty()) {
      while (node) {
        traversal_nodes.push(node);
        node = node->left;
      }

      TreeNode* top_node = traversal_nodes.top();
      traversal_nodes.pop();

      count--;
      if (count == 0) {
        return top_node->val;
      }
      node = top_node->right;
    }

    return -1;
  }
};
