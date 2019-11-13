//https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++){
            bitset<32> s(i);
            if (isSmallPrime(s.count()))
                res++;
        }
        
        return res;
    }
    
    bool isSmallPrime(int x) {
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int L = stringToInteger(line);
        getline(cin, line);
        int R = stringToInteger(line);
        
        int ret = Solution().countPrimeSetBits(L, R);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
