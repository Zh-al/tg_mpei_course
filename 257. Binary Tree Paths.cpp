//https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        helper (root, {}, result);
        return result;
    }
    
    void helper (TreeNode* root, string temp, vector <string>& res){
        if (root != NULL){
            temp += "->" + to_string(root -> val);
            if (root -> left == NULL && root -> right == NULL){
                res.push_back(temp.substr(2,temp.length() - 2));
            }
            helper (root -> left, temp, res);
            helper (root -> right, temp, res);
        }
    }
};
