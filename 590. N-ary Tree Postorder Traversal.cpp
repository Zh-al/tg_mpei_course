//https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector <int> res;
        helper (root, res);
        int n = res.size() - 1;
        for (int i = 0; i < (n + 1) / 2; i++)
            swap (res[i], res[n - i]);
        return res;
    }
    
    void helper (Node* root, vector <int> &res){
        if (root != NULL){
            res.push_back(root -> val);
            for (int i = root -> children.size() - 1; i >= 0; i--)
                helper (root -> children[i], res);
        }
    }
    
};
