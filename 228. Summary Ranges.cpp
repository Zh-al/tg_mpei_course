//https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        if (nums.size() == 1)
            return {to_string(nums[0])};
        vector <string> result;
        string temp;
        temp = to_string (nums[0]);
        if (nums[0] != nums[0 + 1] - 1){
            result.push_back(temp);
        }
        for (int i = 1; i + 1 < nums.size(); i++){
            if (nums[i] != nums[i - 1] + 1){
                
                temp = to_string (nums[i]);
            }
            if (nums[i] != nums[i + 1] - 1){
                if (nums[i] != nums[i - 1] + 1)
                    result.push_back(temp);
                else
                    result.push_back(temp + "->" + to_string(nums[i]));
            }
        }
        if (nums[nums.size() - 1] != nums[nums.size() - 1 - 1] + 1)
            result.push_back(to_string(nums[nums.size() - 1]));
        else
            result.push_back(temp + "->" + to_string(nums[nums.size() - 1]));
        return result;
    }
};
