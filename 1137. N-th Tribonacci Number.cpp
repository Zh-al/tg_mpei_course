//https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    int tribonacci(int n) {
        int temp0 = 0;
        int temp1 = 1;
        int temp2 = 1;
        int temp = 2;
        int temptemp;
        for (int i = 3; i <= n; ++i)
        {
            temp=temp0+temp1+temp2;
            temp0=temp1;
            temp1=temp2;
            temp2=temp;
        }
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        else
        return temp;
    }
};
