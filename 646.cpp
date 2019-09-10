//https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int count = 0;
        bool fl = true;
        int min = 0;
        int max = 0;
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            if (pairs.at(i).at(0) < min)
                min = pairs.at(i).at(0);
            if (pairs.at(i).at(1) > max)
                max = pairs.at(i).at(1);
        }
        int b = min - 1;
        max += 1;
        while (fl)
        {
            fl = false;
            min = max;
            for (size_t i = 0; i < pairs.size(); ++i)
            {
                if (pairs.at(i).at(1) < min && pairs.at(i).at(0) > b)
                {
                    min = pairs.at(i).at(1);
                    fl = true;
                }
            }
            if (fl)
            {
                b = min;
                count += 1;
                
            }
        }
        return count;
    }
};
