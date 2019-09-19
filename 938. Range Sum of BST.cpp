/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int temp = 0;
        if (root == NULL)
            return 0;
        int rval = root->val;
        if (rval >= L) 
            if (rval <= R)
                return (rval + rangeSumBST(root -> left, L, R) + rangeSumBST(root -> right, L, R));
            else
                return (rangeSumBST(root -> left, L, R));
        else
            return (rangeSumBST(root -> right, L, R));
        
    }
};
