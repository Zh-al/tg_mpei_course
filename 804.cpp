//https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> Morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> InMorse;
        int count = 0;
        string str;
        bool fl;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].length(); ++j)
                str += Morse[int(words[i][j])-int('a')];
            fl = 1;
            for (int k = 0; k < count; ++k)
                if (str == InMorse[k])
                    fl = 0;
            if (fl){
                count += 1;
                InMorse.push_back(str);
                
            }
            str.clear();
        
        }
        return count;
    }
};
