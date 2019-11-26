//https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        int temp = N;
        int i = 0;
        while (temp){
            temp >>= 1;
            i++;
        }
        unsigned int mask = ~0;
        mask >>= i;
        mask <<= i;
        return ~N & ~mask;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().bitwiseComplement(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
