//https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ind = 0;
        int maxn = nums [0];
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > maxn){
                maxn = nums[i];
                ind = i;
            }
        for (int i = 0; i < ind; i++)
            if (nums[i] * 2 > maxn)
                return -1;
        for (int i = ind + 1; i < nums.size(); i++)
            if (nums[i] * 2 > maxn)
                return -1;
        return ind;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().dominantIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
