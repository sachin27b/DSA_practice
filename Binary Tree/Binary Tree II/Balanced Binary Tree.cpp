//https://leetcode.com/problems/balanced-binary-tree/description/
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

    int heightFinder(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left_height = heightFinder(root -> left);
        int right_height = heightFinder(root -> right);
        if(abs(left_height - right_height) > 1)
            return -1;
        if(left_height == -1 || right_height == -1)
            return -1;
        else return 1 + max(left_height, right_height);

    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(heightFinder(root) == -1)
            return false;
        else 
            return true;
        
    }
};
