//https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return 0;
        long int order = 1;
        int numerals = 0;
        while (x / order){
            order *= 10;
            numerals++;
        }
        order /= 10;
        for (int i = 0; i < numerals / 2; i++){
            if (x / order != x % 10)
                return 0;
            x %= order;
            x /= 10;
            order /= 100;
        }
        return 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
