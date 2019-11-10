//https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length())
            return addStrings (num2, num1);
        string res;
        int temp = 0;
        int dif = (int)num1.length() - (int)num2.length();
        for (int i = (int)num2.length() - 1; i >= 0; i--){
            int num = (int)num2[i] + (int)num1[i + dif] - 2 * (int)'0' + temp;
            res.insert(0, to_string (num % 10));
            temp = num / 10;
        }
        for (int i = dif - 1; i >= 0; i--){
            int num = (int)num1[i] - (int)'0' + temp;
            res.insert(0, to_string (num % 10));
            temp = num / 10;
        }
        if (temp)
            res.insert(0,"1");
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
