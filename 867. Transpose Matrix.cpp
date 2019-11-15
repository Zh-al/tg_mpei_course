//https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < m; i++){
            vector<int> temp;
            for (int j = 0; j < n; j++)
                temp.push_back(A[j][i]);
            res.push_back(temp);
        }
        return res;
    }
};
