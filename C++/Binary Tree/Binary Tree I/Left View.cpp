//https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
void findLeftView(Node* node, int height, int &max_height, vector<int> &ans)
{
    if(node == NULL)
        return;
    else if(height > max_height)
        {
            max_height = max(height, max_height);
            ans.push_back(node -> data);
        }
    findLeftView(node -> left, height + 1, max_height, ans);
    findLeftView(node -> right, height + 1, max_height, ans);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    
    int height = 0, max_height = 0;
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    else{
            ans.push_back(root -> data);
            findLeftView(root, height, max_height, ans);
            return ans;
                
    }

}
