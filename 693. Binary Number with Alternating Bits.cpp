//https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return !(n >> 1 & n) && (n >> 2 & n) == n >> 2;
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
        int n = stringToInteger(line);
        
        bool ret = Solution().hasAlternatingBits(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
