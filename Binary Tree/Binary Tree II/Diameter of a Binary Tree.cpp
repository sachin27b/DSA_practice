//https://leetcode.com/problems/diameter-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;
    int diameterFinder(TreeNode* root){
        // We need to find the max height at left and right of root.
        if (root == NULL)
            return 0;
        /*at every node i need the max left height and max right height.
        add the left and right height and send it to the parent.
        then parent should check*/
        int left_height, right_height;
        left_height = diameterFinder(root->left);
        right_height = diameterFinder(root->right);
        diameter = max(diameter,
                         left_height + right_height);
        return max(left_height, right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameterFinder(root);
        return diameter;
    }
};
