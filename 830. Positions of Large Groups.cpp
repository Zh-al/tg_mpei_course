//https://leetcode.com/problems/positions-of-large-groups/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        char temp = '#';
        int l = 0, r = 0;
        for (int i = 0; i < S.length(); i++)
            if (S[i] == temp)
                r++;
            else{
                if (r - l >= 2)
                    res.push_back ({l,r});
                l = i;
                r = i;
                temp = S[i];
            }
        if (r - l >= 2)
            res.push_back ({l,r});
        
        return res;
    }
};
