//https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int len = 0;
        s += ' ';
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
                len++;
            else{
                for (int j = 0; j < len / 2; j++)
                    swap (s[i - len + j], s[i - 1 - j]);
                len = 0;
            }         
        }
        s.erase (s.length() - 1);
        return s;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().reverseWords(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
