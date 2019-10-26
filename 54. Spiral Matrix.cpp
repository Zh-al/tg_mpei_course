//https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        int l = 0, r = matrix[0].size() - 1, d = matrix.size() - 1, u = 0;
        int i = 0;
        int j = 0;
        vector<int> result;
        while (l <= r && u <= d){
            i = u;
            j = l;
            while (j <= r){
                result.push_back (matrix[i][j++]);
            }
            i++;
            j--;
            while (i <= d){
                result.push_back (matrix[i++][j]);
            }
            i--;
            if (l < r && u < d){
                j--;
                while (j > l){
                    result.push_back (matrix[i][j--]);
                }
                while (i > u){
                    result.push_back (matrix[i--][j]);
                }
            }
            r--;
            d--;
            l++;
            u++;
        }
        return result;
    }
};
