//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        if (root == p)
            return p;
        if (root == q)
            return q;
        if (root) {
            left = lowestCommonAncestor(root->left, p, q);
            right = lowestCommonAncestor(root->right, p, q);
        }
        if ((left != NULL) && (right != NULL))
            return root;
        if (left != NULL)
            return left;
        if (right != NULL)
            return right;
        else
            return NULL;
    }
};
