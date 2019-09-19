//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i = A.size() / 2 - 2;
        bool fl = 1;
        vector<int> nums;
        while (fl && i < A.size())
        {
            int j = 0;
            while (fl && j < nums.size())
                if (nums[j] == A[i])
                    fl = 0;
                else
                    j++;
            nums.push_back (A[i]);
            ++i;
        }
        if (fl)
            return nums[0];
        else
            return A[i - 1];
    }
};
