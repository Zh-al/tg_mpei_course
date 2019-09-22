//https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        bool fl = 0;
        int i = 0;
            while (!fl && i < nums.size() - 1){
                if (nums[i] == 0)
                    if (nums [i + 1] == 0)
                        fl = 1;
                ++i;
            }
        if (fl)
            return fl;
        if (k == 0)
            return 0;
        if (k < 0)
            k *= -1;
        i = 0;
        while (!fl && i < nums.size() - 1){
            int j = i;
            int s = 0;
            int kol = 0;
            while (!fl && j < nums.size()){
                s += nums[j];
                kol += 1;
                if (s % k == 0 && kol > 1)
                    fl = 1;
                ++j;
            }
            ++i;
        }
        return fl;
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

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        bool ret = Solution().checkSubarraySum(nums, k);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
