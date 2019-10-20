//https://leetcode.com/problems/broken-calculator/

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        while (Y > X){
            result++;
            Y = Y & 1 ? Y + 1 : Y / 2;
        }
        return result + (X - Y);
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int X = stringToInteger(line);
        getline(cin, line);
        int Y = stringToInteger(line);
        
        int ret = Solution().brokenCalc(X, Y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
