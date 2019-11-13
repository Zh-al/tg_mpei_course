//https://leetcode.com/problems/rotated-digits/

class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for (int i = 1; i <= N; i++)
            if (isGood(i))
                res++;
        
        return res;
    }
    
    bool isGood (int x){
        bool fl = false;
        while (x > 0){
            int m = x % 10;
            if (m == 3 || m == 4 || m == 7)
                return false;
            if (m == 2 || m == 5 || m == 6 || m == 9)
                fl = true;
            x /= 10;
        }
        return fl;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().rotatedDigits(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
