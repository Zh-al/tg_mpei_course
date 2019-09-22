//https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0)
            return 0;
        while (num % 4 == 0)
            num /= 4;
        return (num == 1);
    }
};
