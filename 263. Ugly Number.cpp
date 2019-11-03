//https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0)
            return false;
        for (int i = 2; i < 6; i++)
            while (num % i == 0)
                num /= i;
        return num == 1;
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
        int num = stringToInteger(line);
        
        bool ret = Solution().isUgly(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
