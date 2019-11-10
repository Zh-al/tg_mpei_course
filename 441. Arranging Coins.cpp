//https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        long fact = 1;
        int i = 1;
        while (n / fact){
            i++;
            fact += i;
        }
        return i - 1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().arrangeCoins(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
