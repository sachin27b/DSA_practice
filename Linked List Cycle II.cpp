// https://leetcode.com/problems/linked-list-cycle-ii/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* detectStartNode(ListNode* ptr, ListNode* head)
    {
        ListNode* ptr1 = head;
        while(ptr != ptr1)
        {
            ptr1 = ptr1 -> next;
            ptr = ptr -> next;
        }
        return ptr;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && (fast -> next != NULL && fast -> next -> next != NULL))
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                return detectStartNode(slow, head);
            }
        }
        return NULL;
    }
};