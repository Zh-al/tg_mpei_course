//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return 0;
        bool fl = 0, row = 0;
        int i = 0, j = 0;
        const int m = matrix.size(), n = matrix[0].size();
        while (!row && j < m - 1){
            if (matrix[j + 1][0] <= target)
                j++;
            else
                row = 1;
        }
        while (!fl && i < n)
            if (matrix[j][i] == target)
                fl = 1;
            else
                i++;
        return fl;
    }
};
