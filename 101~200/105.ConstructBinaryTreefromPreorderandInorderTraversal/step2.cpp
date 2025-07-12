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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preorder_index = 0;
    int left = 0;
    int right = preorder.size() - 1;
    return BuildTreeHelper(preorder, inorder, preorder_index, left, right);
  }

  TreeNode* BuildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preorder_index,
                            int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int root_value = preorder[preorder_index];
    TreeNode* root = new TreeNode(root_value);

    int division_index = 0;
    for (int i = 0; i < inorder.size(); i++) {
      if (inorder[i] == root_value) {
        division_index = i;
        break;
      }
    }

    preorder_index++;
    root->left = BuildTreeHelper(preorder, inorder, preorder_index, left, division_index - 1);
    root->right = BuildTreeHelper(preorder, inorder, preorder_index, division_index + 1, right);
    return root;
  }
};
