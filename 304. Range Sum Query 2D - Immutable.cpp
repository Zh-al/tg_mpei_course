//https://leetcode.com/problems/range-sum-query-2d-immutable/solution/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size())
            return;
        sum.resize(matrix.size() + 1);
        for (int i = 0; i < sum.size(); i++)
            sum[i].resize(matrix[0].size() + 1);
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                sum [i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum [i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum [row2 + 1][col1] - sum[row1][col2 + 1] + sum[row1][col1];
    }
    
private:
    vector <vector <int> > sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
