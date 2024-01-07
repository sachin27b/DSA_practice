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

    ListNode* reverse_list(ListNode* head)
    {
        ListNode* newHead;
        ListNode* front;
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        newHead = reverse_list(head -> next);
        front = head -> next;
        front -> next = head;
        head -> next = NULL;

        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ptr1 = head;
        ListNode* ptr2 = NULL;

        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ptr2 = reverse_list(slow -> next);

        while(ptr2 != NULL)
        {
            if(ptr1 -> val != ptr2 -> val)
            {
                return false;
            }
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        return true;
    }
};