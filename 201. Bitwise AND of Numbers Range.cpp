//https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            ++i;        
        }
        return m<<i;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().rangeBitwiseAnd(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
