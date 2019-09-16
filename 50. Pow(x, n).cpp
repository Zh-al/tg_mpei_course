//https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, long int n) {
        if (x == 1)
            return 1;
        if (n < 0)
        {
            x = 1 / x;
            n *= (-1);
        }
        double result = 1;
        while (n != 0)
            if (n & 1)
            {
                result *= x;
                n--;
            }
            else
            {
                x *= x;
                n /= 2;
            }
        return result;
    }
};
