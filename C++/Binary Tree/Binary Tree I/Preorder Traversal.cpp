//https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
    void preTraversal(TreeNode* node, vector<int> &traversal)
    {
        if(node == nullptr)
            return;
        else
        {
            traversal.push_back(node -> val);
            preTraversal(node -> left, traversal);
            preTraversal(node -> right, traversal);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        preTraversal(root, traversal);
        return traversal;
    }
};
