//https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int count = 0;
        map <char, int> ch;
        for (size_t i = 0; i < chars.length(); i++)
            ch [chars[i]] += 1;
        for (size_t i = 0; i < words.size(); ++i){
            map <char, int> temp = ch;
            bool fl = 1;
            size_t j = 0;
            while (fl && j < words[i].length()){
                if (temp[words[i][j]] == 0)
                    fl = 0;
                else{
                    temp[words[i][j]] -= 1;
                    j++;
                    
                }
            }
            if (fl)
                count += words[i].length();
        }
        return count;
    }
};
