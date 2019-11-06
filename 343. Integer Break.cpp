//https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        else if (n % 3 == 0)
            return pow (3, n / 3);
        else if (n % 3 == 1)
            return 4 * pow (3, ((n - 4) / 3));
        else
            return 2 * pow (3, (n / 3));
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().integerBreak(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
