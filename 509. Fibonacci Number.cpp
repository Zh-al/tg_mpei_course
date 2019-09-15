//https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        int temp0 = 0;
        int temp1 = 1;
        int temp = 1;
        for (int i = 2; i <= N; ++i)
        {
            temp=temp0+temp1;
            temp0=temp1;
            temp1=temp;
        }
        if (N == 0)
            return 0;
        //else if (n == 1 || n == 2)
        //    return 1;
        else
            return temp;
    }
};
