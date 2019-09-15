//https://leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
public:
    int trailingZeroes(int n) {
        int temp = 0;
        long int p = 5;
        while (p <= n)
        {
            temp += n / p;
            p *= 5;
        }
        return temp;
    }
};
