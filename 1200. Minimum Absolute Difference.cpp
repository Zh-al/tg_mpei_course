//https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort (arr.begin(),arr.end());
        int min = abs(arr[0] - arr[1]);
        vector<vector<int>> result;
        for (size_t i = 1; i + 1 < arr.size(); ++i)
            if (abs(arr[i] - arr[i + 1]) < min)
                min = abs(arr[i] - arr[i + 1]);
        for (size_t i = 0; i + 1 < arr.size(); i++)
            if (abs(arr[i] - arr[i + 1]) == min){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i + 1]);
                result.push_back (temp);
            }
        return result;
    }
};
