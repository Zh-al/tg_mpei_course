//https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        map <char, int> sec, gue;
        int cntA = 0, cntB = 0;
        for (int i = 0; i < secret.length(); i++){
            if (secret[i] == guess[i])
                cntA++;
            sec[secret[i]]++;
            gue[guess[i]]++;
        }
        res += to_string(cntA) + 'A';
        for (auto i : sec){
            cntB += min (sec[i.first], gue[i.first]);
        }
        res += to_string (cntB - cntA) + 'B';
        return res;
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
        string secret = stringToString(line);
        getline(cin, line);
        string guess = stringToString(line);
        
        string ret = Solution().getHint(secret, guess);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
