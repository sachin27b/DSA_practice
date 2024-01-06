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

//https://leetcode.com/problems/reverse-nodes-in-k-group/description/
class Solution {
public:

    ListNode* reverse_list(ListNode* head, int k)
    {
        ListNode* newHead;
        ListNode* front;
        if(k == 1)
        {
            return head;
        }
        newHead = reverse_list(head -> next, --k);
        front = head -> next;
        front -> next = head;
        head -> next = NULL;

        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* itr = head;
        ListNode* forward_head;
        ListNode* newHead;
        int count = 0;
        for(int i = 0; i < k; i++)
        {
            if(itr != NULL)
            {
                count++;
                itr = itr -> next;
            }
            
        }

        if(count != k)
        {
            return head;
        }

        forward_head = reverseKGroup(itr, k);
        newHead = reverse_list(head, k);
        head -> next = forward_head;
        return newHead;

    }
};