//https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int s = 1;
        /*long long int fact = 1;
        for (int i = 2; i <= n; ++i)
            fact *= i;
        long long int fact1 = fact;
        long long int fact2 = 1;*/
        long long int last = 1;
        for (int i = 1; i <= (n +  1) / 2; ++i)
        {   
            /*fact /= (n - i + 1);
            fact1 /= (n - 2 * i + 2) * (n - 2 * i + 1);
            fact2 *= i;*/
            last *= ((n - 2 * i + 2) * (n - 2 * i + 1));
            last /= ((n - i + 1) *  i);
            s += last;
            
        }
        return s;
    }
};
