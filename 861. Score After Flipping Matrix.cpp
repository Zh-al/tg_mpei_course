//https://leetcode.com/problems/score-after-flipping-matrix/

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        
        int pow2 = pow (2, A[0].size() - 1);
        int n = A.size();
        int m = A[0].size();
        
        for (int i = 0; i < n; ++i)
            if (!A[i][0])
                for (int j = 0; j < m; ++j)
                    A[i][j] = (A[i][j] + 1) % 2;
        
        int s = pow2 * n;
        
        for (int j = 1; j < m; ++j){
            int k = 0;
            for (int i = 0; i <n; ++i)
                if (A[i][j])
                    ++k;
            pow2 /= 2;
            s += pow2 * max(n - k, k);
        }
        return s;
    }
};
