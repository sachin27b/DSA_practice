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

// https://leetcode.com/problems/add-two-numbers/description/


class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int res, sum, carry = 0;
        ListNode* curr = new ListNode();
        ListNode* start = curr;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        while((h1 != NULL || h2 != NULL) || carry != 0)
        {
            sum = 0;
            ListNode* ptr = new ListNode();

            
            if(h1 != NULL)
            {
                sum += h1 -> val;
                h1 = h1 -> next;
            }

            if(h2 != NULL)
            {
                sum += h2 -> val;
                h2 = h2 -> next;
            }
            if(carry != 0)
            {
                sum += carry;
                carry = 0;
            }
            res = sum % 10;
            carry = sum / 10;
            ptr -> val = res;
            curr -> next = ptr;
            curr = ptr;

        }
        return start -> next;
    }
};