//https://leetcode.com/problems/perfect-number/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }

            }
        }
        return sum - num == num;
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
        
        bool ret = Solution().checkPerfectNumber(num);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
