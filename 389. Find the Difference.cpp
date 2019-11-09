//https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        map <char, int> let;
        for (int i = 0; i < t.size(); i++)
            let[t[i]]++;
        for (int i = 0; i < s.size(); i++)
            let[s[i]]--;
        for (auto i: let)
            if (i.second)
                return i.first;
        return 0;
    }
};
