//https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int inf = 10000;
        vector < vector < int > > GR (N);
        for (int i = 0; i < N; i++)
            GR[i].resize (N, 0);
        for (int i = 0; i < times.size(); i++)
            GR[times[i][0] - 1][times[i][1] - 1] = times [i][2];
        //Алгоритм Дейкстры
        vector <bool> visited (N, false);
        vector <int> distance (N, inf);
        int index = -1;
        int u, count;
        distance[K - 1] = 0;
        for (count = 0; count < N - 1; count++) {
            int min = inf;
            for (int i = 0; i < N; i++)
                if (!visited[i] && distance[i] <= min) {
                    min = distance[i];
                    index = i;
                }
            u = index;
            visited[u] = true;
            for (int i = 0; i < N; i++)
                if (!visited[i] && GR[u][i] && distance[u] != INT_MAX && distance[u] + GR[u][i] < distance[i])
                    distance[i] = distance[u] + GR[u][i];
        }
        //конец алгоритма Дейкстры
        int max = 0;
        for (int i = 0; i < N; i++)
            if (distance [i] > max)
                max = distance [i];
        if (max == inf)
            return -1;
        return max;
        //return max == inf ? -1 : max;
    }
};
