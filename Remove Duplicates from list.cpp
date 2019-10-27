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
    ListNode* deleteDuplicates(ListNode* head) {
        helper (head);
        return head;
   }
    
    void helper (ListNode* head){
        if (head -> next != NULL){
            if (head -> val == head -> next -> val){
                head -> next = head -> next -> next;
                helper (head);
            }
            helper (head -> next);
        }
    }
};
