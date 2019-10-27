//https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int ToZero = -INT_MAX;
        const int n = matrix.size();
        const int m = matrix[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    for (int k = 0; k < n; k++){
                        if (matrix[k][j])
                            matrix[k][j] = ToZero;
                    }
                    for (int k = 0; k < m; k++){
                        if (matrix[i][k]){
                            matrix[i][k] = ToZero;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == ToZero){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
