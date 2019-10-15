//https://leetcode.com/problems/redundant-connection/

#include <unordered_map>
class Solution {
private:
    vector<int> parent;
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
        parent.push_back(0);
        for (int i = 0; i <= edges.size(); ++i) {
            parent.push_back(i + 1);
        }
        for (int i = 0; i < edges.size(); ++i) {
            int first = edges[i][0], second = edges[i][1];
            if (parent[find(first)] == parent[find(second)]) return {first, second};
            unit(first, second);
        }
        return vector<int>();
    }
private:
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
    void unit(int x, int y) {
        int xParent = find(x);
        parent[find(y)] = xParent;
    }
};
