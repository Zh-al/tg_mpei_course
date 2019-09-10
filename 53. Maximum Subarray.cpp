//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int max;
        if (nums.at(0) < 0)
            max = nums.at(0);
        else
            max = nums.at(0) * (-1);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            s = 0;
            for (size_t j = i; j < nums.size(); ++j)
            {
                s += nums.at(j);
                if (s > max)
                    max = s;
            }
        }
        return max;
    }
};
