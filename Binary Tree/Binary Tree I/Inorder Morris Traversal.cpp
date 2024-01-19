//https://leetcode.com/problems/binary-tree-inorder-traversal/description/
class Solution{
    public:

    vector<int> inorderTraversal(TreeNode* root)
    {
        TreeNode* cur = root;
        TreeNode* prev;
        vector<int> ans;
        /*At every node there are two choices - going left or right.
        if left node doesn't exist then it means since it is inorder we
        push the current node to our answer.
        if left is not null then we use prev pointer and traverse to 
        the right most node. now this end of right pointer can be null or
        pointed to cur.
        if it is null then it needs to be pointed to cur so that when cur
        gets to this node it can traverse back to inorder successor.
        if it is not null then it will be already pointed to cur.
        this condition is checked only if the cur has traversed from a leaf
        and traversed back to inorder successor i.e when the inner while loop 
        terminates with prev->right!=cur condition. so in the else condition
        the thread to cur has to terminated and cur is now at the node which 
        is to be pushed to answer. and then the cur is moved to right.*/
        while(cur != nullptr)
        {
            if(cur -> left == nullptr)
            {
                ans.push_back(cur -> val);
                cur = cur -> right;
            }
            else
            {
                prev = cur -> left;
                while(prev -> right != nullptr && prev -> right != cur)
                {
                    prev = prev -> right;
                }
                if(prev -> right == nullptr)
                {
                    prev -> right = cur;
                    cur = cur -> left;
                }
                else
                {
                    prev -> right = nullptr;
                    ans.push_back(cur -> val);
                    cur = cur -> right;
                }
            }
        }
    return ans;
    }
    };
