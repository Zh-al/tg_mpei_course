//https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> balance(N + 1);
      for (const vector <int> &t : trust){
          balance[t[0]]--;
          balance[t[1]]++;
      }
      for (int i = 1; i <= N; ++i) 
          if (balance[i] == N - 1) 
              return i;
      return -1;
    }
};
