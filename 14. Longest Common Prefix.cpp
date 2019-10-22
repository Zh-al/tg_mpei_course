//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return {};
        if (strs.size() == 1)
            return strs[0];
        string result;
        //bool fl = 1;
        int index = 0;
        while (true){
            for (int i = 0; i < strs.size() - 1; i++){
                if (strs[i].length() == index || strs[i + 1].length() == index)
                    return result;
                if (strs[i][index] != strs[i + 1][index])
                    return result;
            }
            result.push_back (strs[0][index++]);
        }
        return result;
    }
};
