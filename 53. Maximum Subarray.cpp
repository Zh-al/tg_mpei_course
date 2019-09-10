//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int temp = nums[0];
        for (size_t i = 0; i < nums.size(); ++i)
        {
            s += nums[i];
            if (s < nums[i])
                s = nums[i];
            temp = max (temp, s);
        }
        return temp;
    }
};
