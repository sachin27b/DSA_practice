//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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

    void intraversal(TreeNode* node, vector<int> &traversal)
    {
        if(node == nullptr)
            return;
        else
        {
            
            intraversal(node -> left, traversal);
            traversal.push_back(node -> val);
            intraversal(node -> right, traversal);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        intraversal(root, traversal);
        return traversal; 
    }
};
