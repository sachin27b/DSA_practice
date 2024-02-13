//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    map<int, int> m;

    TreeNode* buildTree2(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd)
    {
        /*in every call we have to do the following -
        1. decide the node to be pushed to tree. for we need the root.
        root is the first element of preorder.
        2. Decide new preorder and post order*/
        if(preStart > preEnd || inStart > inEnd)
            return NULL;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int idx = m[preorder[preStart]];
        
        // left
            // inorder from start till idx - 1
            // preorder start + 1 till size of(new inorder)
        node -> left = buildTree2(preorder, preStart + 1, preStart + idx - inStart, inorder, inStart, idx - 1);
        // // right
        //     // inorder from idx + 1 till end
        //     // preorder preorder of left call + 1 till end

        node -> right = buildTree2(preorder, preStart + idx - inStart + 1, preEnd, inorder, idx + 1, inEnd);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* node = new TreeNode(); // we need to map key(values in preorder) to index
        if(preorder[0] == -1)
        {
            node -> val = -1;
            return node;
        }
        int size = preorder.size();

        for(int i = 0; i < size; i++)
        {
            m[inorder[i]] = i;
        }
        return buildTree2(preorder, 0, size - 1, inorder, 0, size -1);
    }
};
