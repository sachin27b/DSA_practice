//https://leetcode.com/problems/binary-tree-postorder-traversal/description/
class Solution {
public:
    void postTraversal(TreeNode* node, vector<int> &traversal)
    {
        if(node == nullptr)
            return;
        else
        {

            postTraversal(node -> left, traversal);
            postTraversal(node -> right, traversal);
            traversal.push_back(node -> val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        preTraversal(root, traversal);
        return traversal;
    }
};
