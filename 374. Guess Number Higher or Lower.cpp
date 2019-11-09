//https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (guess (1) == 0)
            return 1;
        if (guess (n) == 0)
            return n;
        int l = 1;
        int r = n;
        int res = guess (l + (r - l) / 2);
        while (res != 0){
            if (res == 1)
                l = l + (r - l) / 2;
            else 
                r = l + (r - l) / 2;
            res = guess (l + (r - l) / 2);
        }
        return l + (r - l) / 2;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int pick = stringToInteger(line);
        
        int ret = Solution().guessNumber(n, pick);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
