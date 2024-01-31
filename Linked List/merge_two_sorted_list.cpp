/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* temp = NULL;
        ListNode* res;

        if(h2 == NULL)
        {
            return h1;
        }
        if(h1 == NULL)
        {
            return h2;
        }
        /*Below if else statement is to save the smallest element as head which is res.
        And start comparing the elements from the next of res and the other list.*/
        if(h1 -> val < h2 -> val)
        {
            res = h1;
            temp = h1;
            h1 = h1 -> next;
        }
        else
        {
            res = h2;
            temp = h2;
            h2 = h2 -> next;
        }

        while(h1 != NULL && h2 != NULL)
        {
            if(h1 -> val < h2 -> val)
            {
                temp -> next = h1; 
                temp = h1;
                h1 = h1 -> next;
            }

            else
            {
                temp -> next = h2;
                temp = h2;
                h2 = h2 -> next;
            }
            /*Temp is always saving the previous smallest node because in the next iteration that element
            has to be pointedd to the next smallest element.*/
        }
        
        if(h2 == NULL)
        {
            temp -> next = h1;
        }
        else
        {
            temp -> next = h2;
        }

        return res;       
    }
};