//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        if (nums.size() == 1)
            return {new TreeNode(nums[0])};
        nums.insert (nums.begin(),0);
        TreeNode* result = new TreeNode (nums[(nums.size() - 1) / 2 + 1]);
        //TreeNode* result_begin = result;
        helper (result, nums, 1, (nums.size() - 1) / 2, (nums.size() - 1) / 2 + 2, nums.size() - 1);
        return result;
    }
        
    void helper (TreeNode* root, vector <int> nums, int left_begin, int left_end, int right_begin, int right_end){
        if (left_end - left_begin >= 0){
            root -> left = new TreeNode (nums[(left_end + left_begin + 1) / 2]);
            helper (root -> left, nums, left_begin, (left_end + left_begin + 1) / 2 - 1, 
                    (left_end + left_begin + 1) / 2 + 1, left_end);
        }
        if (right_end - right_begin >= 0){
            root -> right = new TreeNode (nums[(right_end + right_begin + 1) / 2]);
            helper (root -> right, nums, right_begin, (right_end + right_begin + 1) / 2 - 1, 
                    (right_end + right_begin  + 1) / 2 + 1, right_end);
        }
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().sortedArrayToBST(nums);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
