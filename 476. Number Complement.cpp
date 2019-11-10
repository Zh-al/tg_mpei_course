//https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        int ret = Solution().findComplement(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
