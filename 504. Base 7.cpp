//https://leetcode.com/problems/base-7/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string res;
        bool negative = 0;
        if (num < 0){
            negative = 1;
            num = -num;
        }
        while (num){
            res.insert(0, to_string(num % 7));
            num /= 7;
        }
        if (negative)
            res.insert(0, "-");
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        string ret = Solution().convertToBase7(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
