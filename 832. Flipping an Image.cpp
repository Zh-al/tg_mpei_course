//https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> result;
        //vector<int> ResultRow;
        //ResultRow.clear();
        for (vector <int> row : A)
        {
            vector<int> ResultRow;
            for (int i = row.size() - 1; i >= 0; --i)
                ResultRow.push_back ((row[i] + 1) % 2);
            result.push_back(ResultRow);
            //ResultRow.clear();
        }
        return result;
    }
};
