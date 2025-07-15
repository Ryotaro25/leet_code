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
  TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
    if (!node) {
      return nullptr;
    }
    int node_val = node->val;
    int p_val = p->val;
    int q_val = q->val;
    if (p_val < node_val && q_val < node_val) {
      node =  lowestCommonAncestor(node->left, p, q);
    } else if (p_val > node_val && q_val > node_val) {
      node = lowestCommonAncestor(node->right, p, q);
    }
    return node;
  }
};
