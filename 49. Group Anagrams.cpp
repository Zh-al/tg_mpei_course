//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map <string, vector<string>> anagrams;
        for (int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            string comp = strs[i];
            sort(comp.begin(), comp.end());
            anagrams[comp].push_back(temp);
        }
        for (auto i : anagrams)
            result.push_back(i.second);
        return result;
    }
};
