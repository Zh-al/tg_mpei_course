//https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> MP;
        vector<string> res;  
        for(int i = 0; i < int(s.size()) - 9; ++i)
            if(MP[s.substr(i,10)]++ == 1 )
               res.push_back(s.substr(i,10));
               
        return res;
    }
};
