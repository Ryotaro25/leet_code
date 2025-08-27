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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> first_nodes;
    first_nodes.push(p);
    queue<TreeNode*> second_nodes;
    second_nodes.push(q);
    while (!first_nodes.empty() && !second_nodes.empty()) {
      auto current_first = first_nodes.front();
      first_nodes.pop();

      auto current_second = second_nodes.front();
      second_nodes.pop();

      if (!current_first && !current_second) {
        continue;
      }
      if (!current_first || !current_second) {
        return false;
      }
      if (current_first->val != current_second->val) {
        return false;
      }
      first_nodes.push(current_first->left);
      second_nodes.push(current_second->left);
      first_nodes.push(current_first->right);
      second_nodes.push(current_second->right);
    }
    return true;
  }
};
