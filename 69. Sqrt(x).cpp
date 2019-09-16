//https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int temp = 0;
        int result = 0;
        
        //int remainder = 0;
        long int divider = 0;
        long int dividend = 0;
        
        int NumberOfDigits = 0;
        
        temp = x;
        while (temp != 0)
        {
            temp /= 10;
            NumberOfDigits += 1;
        }
        
        temp = x;
        for (int i = (NumberOfDigits - 1) / 2 + 1; i >= 1; --i)
        {
            dividend += temp / (int) pow (10, (i - 1) * 2);
            //dividend += remainder;
            temp %= (int)pow (10, (i - 1) * 2);
            divider = result * 20 + 9;
            while (dividend < (divider * (divider % 10)))
                divider -= 1;
            //divider += 1;
            if (divider % 10 != 0)
                dividend = (dividend - (divider * (divider % 10))) * 100;
            else
                dividend *= 100;
            //remainder = dividend % (divider * divider) * 100;
            result *= 10;
            result += divider % 10;
        }
        return result;
    }
};
