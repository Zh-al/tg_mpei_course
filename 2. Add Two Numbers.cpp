//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *result = new ListNode(0);
        ListNode *fresult = result;
        int temp = 0;
        int val1, val2;
        result->val = (result->val + l1->val + l2->val) % 10; 
        temp = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;      
        result->next = new ListNode(temp);
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
                val1 = 0;
            else
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2 == NULL)
                val2 = 0;
            else
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            result = result->next;
            temp = (temp + val1 + val2) / 10;
            result->val = (result->val + val1 + val2) % 10;       
            result->next = new ListNode(temp); 
        }
        if (temp == 0)
            result->next = NULL;
        return fresult;
    }
};
