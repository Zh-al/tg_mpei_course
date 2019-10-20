//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    int maxDepth(Node* root) {
        int max_depth = 0;
        helper (root, 1, max_depth);
        return max_depth;
    }
    
    void helper (Node* root, int depth, int& max_depth){
        if (root != NULL){
            if (depth > max_depth)
                max_depth = depth;
            for (int i = 0; i < root -> children.size(); i++)
                helper (root -> children[i], depth + 1, max_depth);
        }
    }
};
