//https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map <int, int> count;
        int res = 0;
        for(auto i: dominoes){
            res += count[max(i[0],i[1]) * 10 + min(i[0],i[1])]++;
        }
        return res;
    }
};
