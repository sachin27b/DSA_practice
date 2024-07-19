//https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        int max_width = 0;
        while(!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int left = 0, right = 0;
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front().first;
                int idx = q.front().second;
                if(i == 0)
                    left = q.front().second;
                if(i == size - 1)
                    right = q.front().second;
                if(node -> left != NULL)
                    q.push({node -> left, (long(idx-min))*2 + 1});
                    //using long here because of overflow
                if(node -> right != NULL)
                    q.push({node -> right, (long(idx-min))*2 + 2});
                q.pop();
            }
            max_width = max(max_width, right - left + 1);
        }
        return max_width;
    }
};
