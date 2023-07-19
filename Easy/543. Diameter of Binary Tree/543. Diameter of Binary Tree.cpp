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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0 ;
        int leftside = maxDepth(root->left) ;
        int rightside = maxDepth(root->right) ;
        return 1 + max(leftside, rightside) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0 ;
        int x = max(maxDepth(root->left) + maxDepth(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right))) ;
        return x ;
    }
};