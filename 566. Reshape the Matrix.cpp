//https://leetcode.com/problems/reshape-the-matrix/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> temp;
        vector<int> tempRow;
        if (r * c != nums.size() * nums.at(0).size())
            return nums;
        else
        {
            int nr, nc = 0;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                for (size_t j = 0; j < nums.at(0).size(); ++j)
                {
                    tempRow.push_back(nums.at(i).at(j));
                    nc += 1;
                    if (nc == c)
                    {
                        temp.push_back(tempRow);
                        tempRow.clear();
                        nc = 0;
                        //nr += 1;
                    }
                }
            }
            return temp;
        }
    }
};
