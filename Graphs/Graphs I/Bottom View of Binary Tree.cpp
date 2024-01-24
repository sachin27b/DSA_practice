//https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
#include<queue>
#include<map>
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        queue<pair<Node*, int>> q;
        map<int, int> mapp;
        q.push({root, 0});
        // map[root -> data] = 0;
        while(!q.empty())
        {
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mapp[level] = node -> data;
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
