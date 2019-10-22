//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;
        long int order = 1;
        int last_number = x % 10;
        bool negative = 0;
        long int number = x;
        if (number < 0){
            negative = 1;
            number = -number;
        }
        int last_number_x = number % 10;
        while (number / order)
            order *= 10;
        long int reverse_order = 1;
        int result = 0;
        order /= 10;
        while (order){
            result += number / order * reverse_order;
            number %= order;
            reverse_order *= 10;
            order /= 10;
        }
        if (result / (reverse_order / 10) != last_number_x)
            return 0;
        return negative ? -result : result;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
