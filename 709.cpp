//https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string str) {
        int dif = (int)('A') - (int)('a');
        string temp;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A'&& str[i] <= 'Z') {
                temp += str[i] - dif; 
            }
            else {
                temp += str[i];
            }
        }
    return temp; 
    }
};
