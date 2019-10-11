//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1'){
                    cnt++;
                    DeleteIsland (i, j, grid);
                }
        return cnt;
    }
    void DeleteIsland (int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '0';
        if (i > 0 && grid [i - 1][j] == '1')
            DeleteIsland (i - 1, j, grid);
        if (j > 0 && grid [i][j - 1] == '1')
            DeleteIsland (i, j - 1, grid);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1')
            DeleteIsland (i + 1, j, grid);
        if (j < grid[0].size() - 1 && grid [i][j + 1] == '1')
            DeleteIsland (i, j + 1, grid);
    }
};
