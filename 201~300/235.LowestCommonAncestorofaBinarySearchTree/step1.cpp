/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lowest_common_ancestor = root;
    lowest_common_ancestor = TraverseTree(root, p, q, lowest_common_ancestor);
    return lowest_common_ancestor;
  }

  TreeNode* TraverseTree(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* lowest_common_ancestor) {
    if (!node) {
      return nullptr;
    }
    lowest_common_ancestor = node;

    int node_val = node->val;
    int p_val = p->val;
    int q_val = q->val;
    if (p_val < node_val && q_val < node_val) {
      return TraverseTree(node->left, p, q, lowest_common_ancestor);
    }
    if (p_val > node_val && q_val > node_val) {
      return TraverseTree(node->right, p, q, lowest_common_ancestor);
    }
    return lowest_common_ancestor;
  }
};
