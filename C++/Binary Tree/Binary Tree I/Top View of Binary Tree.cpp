//https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
#include<map>
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    
    vector<int> topView(Node *root)
    {
        map<int, int> mapp;
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        /*For bottom view and top view level order traversal is used because
        at each height you need to check level wrt to root level 0.*/
        while(!q.empty())
        {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(mapp.find(level) == mapp.end())
            {
                mapp[level] = node -> data;
            }
            if(node -> left != NULL)
                q.push({node -> left, level - 1});
            if(node -> right != NULL)
                q.push({node -> right, level + 1});
        }
        map<int, int>::iterator itr;
        vector<int> ans;
        for(itr = mapp.begin(); itr != mapp.end(); itr++)
        {
            ans.push_back(itr -> second);
        }
        
        return ans;
    }

};
