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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // if length is odd then fast -> next = NULL, if length is even then
        // fast = NULL

        // fast != NULL && fast -> next != NULL both has to be true because if
        // it is a single element list the we cannot get fast -> next -> next.
        // This would give null pointer error
        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        // Slow pointer points to the middle element.
        return slow;

    }
};