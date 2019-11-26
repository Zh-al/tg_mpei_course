//https://leetcode.com/problems/occurrences-after-bigram/

class Solution {
public:
    vector<string> findOcurrences(string raw_text, string first, string second) {
        vector<string> res;
        auto bigram = " " + first + " " + second + " ", text = " " + raw_text;
        auto p = text.find(bigram);
        while (p != string::npos) {
            auto p1 = p + bigram.size(), p2 = p1;
            while (p2 < text.size() && text[p2] != ' ') 
                ++p2;
            res.push_back(text.substr(p1, p2 - p1));
            p = text.find(bigram, p + 1);
        }
        return res;
    }
};
