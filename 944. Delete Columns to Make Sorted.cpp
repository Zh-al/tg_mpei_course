//https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int count = 0;
        
        for (int i = 0; i < A[0].length(); ++i){
            int j = 0;
            bool fl = 1;
            while (fl && j < A.size() - 1)
                if (A[j][i] <= A[j + 1][i])
                    j++;
                else
                    fl = 0;
            if (j != A.size() - 1)
                count += 1;
        }
        return count;
    }
};
