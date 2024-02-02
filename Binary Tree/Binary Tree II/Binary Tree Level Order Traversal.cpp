//https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; int i = 0;
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        q.push(root);
        while(!q.empty())
        {
            vector<int> vec;
            int size = q.size(); 
            // q.size() changes dynamically, so it has to be acquired before the for loop
            for(i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node -> val);
                if(node -> left != NULL)
                {
                    q.push(node -> left);
                }
                if(node -> right != NULL)
                {
                    q.push(node -> right);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }

};
