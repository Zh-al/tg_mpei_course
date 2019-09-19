//https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int i = 0;
        for (char c : S)
        {
            if (c == '(')
                i++;
            else
                --i;
            if ((i != 1 || c != '(') && (i != 0 || c != ')'))
                result.push_back(c);
        }
        return result;
            
    }
};
