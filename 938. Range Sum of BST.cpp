//https://leetcode.com/problems/range-sum-of-bst/

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
        if (root->val >= L && root->val <= R)
            temp = root->val;
        return (temp + rangeSumBST(root -> left, L, R) + rangeSumBST(root -> right, L, R));
    }
};
