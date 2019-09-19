//https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;
        for (int num: A)
            if (num & 1)
                odd.push_back(num);
            else
                even.push_back(num);
        even.insert (even.end(),odd.begin(),odd.end());
        return even;
    }
};
