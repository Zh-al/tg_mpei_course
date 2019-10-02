//https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *temp = root;
        int cnt = 0;
        vector<ListNode*> result;
        while (temp != NULL){
            cnt ++;
            temp = temp -> next;
        }
        for (int i = 0; i < cnt % k; ++i){
            ListNode *temp1 = new ListNode (root->val);
            root = root -> next;
            ListNode *temp1_begin = temp1;
            for (int j = 0; j < cnt / k; ++j){
                temp1 -> next = new ListNode (root -> val);
                root = root -> next;
                temp1 = temp1 -> next;
            }
            result.push_back (temp1_begin);
        }
        for (int i = 0; i < k - cnt % k; ++i){
            if (root == NULL){
                ListNode *temp1_begin = NULL;
                result.push_back (temp1_begin);
            }
            else{
                ListNode *temp1 = new ListNode (root->val);
                root = root -> next;
                ListNode *temp1_begin = temp1;
                for (int j = 1; j < cnt / k; ++j){
                    temp1 -> next = new ListNode (root -> val);
                    root = root -> next;
                    temp1 = temp1 -> next;
                }
                result.push_back (temp1_begin);
            }
            
        }
        return result;
    }
};
