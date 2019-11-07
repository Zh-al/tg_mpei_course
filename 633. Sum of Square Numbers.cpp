//https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int) b)
                return true;
        }
        return false;
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
        int c = stringToInteger(line);
        
        bool ret = Solution().judgeSquareSum(c);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
