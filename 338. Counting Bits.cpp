//https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>a;
        a.push_back(0);
        for(int i=1;i<=num;i++)
        {
            if(i % 2 == 1)
                a.push_back(a[i-1]+1);
            else
                a.push_back(a[i/2]);
        }
        return a;
    }
};
