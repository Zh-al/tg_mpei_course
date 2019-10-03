//https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root) {
        if (root == NULL)
            return 0;
        int diff_right = 0;
        int diff_left = 0;
        int val_root = root -> val;
        int val_right = 0;
        int val_left = 0;
        if (root -> right != NULL){
            val_right = root -> right -> val;
            helper (root -> right, max (val_root, val_right), 
                    min (val_root, val_right), diff_right);
        }
        if (root -> left != NULL){
            val_left = root -> left -> val;
            helper (root -> left, max (val_root, val_left), 
                    min (val_root, val_left), diff_left);
        }
        return (max (diff_left, diff_right));
    }
    
    void helper (TreeNode* root, int val1, int val2, int& diff){
        if (root == NULL)
            return;
        int val_temp = root -> val;
        /*int val_change = 0;
        if (abs(val1 - val_temp) > diff){
            diff = abs(val1 - val_temp);
            val_change = 2;
        }
        if (abs(val2 - val_temp) > diff){
            diff = abs(val2 - val_temp);
            val_change = 1;
        }*/
        if (val_temp > val1)
            val1 = val_temp;
        if (val_temp < val2)
            val2 = val_temp;
        if (abs(val1 - val2) > diff)
            diff = abs(val1- val2);
        //val2 = (abs(val1 - val_temp) < abs (val2 - val_temp) ? val2 : val1);
        //val1 = val_temp;
        helper (root -> right, val1, val2, diff);
        helper (root -> left, val1, val2, diff);

    }
        
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxAncestorDiff(root);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
