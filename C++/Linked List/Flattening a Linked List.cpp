//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1


Node* merge2Lists(Node* head)
{
    Node* list1 = head;
    Node* list2;
    if(head -> next == NULL)
    {
        return head;
    }
    
    list2 = merge2Lists(head -> next);
    
    Node* start = new Node(0);
    Node* prev_node = start;
    
    while(list1 != NULL && list2 != NULL){
        
        Node* newNode = new Node(0);
        
        if(list2 -> data < list1 -> data)
        {
            newNode -> data = list2 -> data;
            prev_node -> bottom = newNode;
            prev_node = newNode;
            list2 = list2 -> bottom;
        }
        
        else
        {
            newNode -> data = list1 -> data;
            prev_node -> bottom = newNode;
            prev_node = newNode;
            list1 = list1 -> bottom;
        }
    }
    
    if(list1 != NULL)
    {
        prev_node -> bottom = list1;
    }
    if(list2 != NULL)
    {
        prev_node -> bottom = list2;
    }
    
    return start -> bottom;
    
}
Node *flatten(Node *root)
{
   // Your code here
   return merge2Lists(root);
}

