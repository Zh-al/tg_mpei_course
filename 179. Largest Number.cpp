https://leetcode.com/problems/largest-number/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        bool OnlyZero = 1;
        for (int i = 0; i < nums.size(); i++){
            temp.push_back(to_string(nums[i]));
            if (nums[i] != 0)
                OnlyZero = 0;
        }
        if (OnlyZero)
            return "0";
        sort (temp.begin(), temp.end(), compare);
        string result;
        for (int i = 0; i < temp.size(); i++)
            result += temp[i];
        return result;
    }
    
    /*static bool compare (const string& lhs, const string& rhs){
        int i = 0;
        while (i < lhs.length() && i < rhs.length()){
            if (lhs[i] > rhs[i])
                return 1;
            else if (lhs[i] < rhs[i])
                return 0;
            else
                i++;
        }
        if (lhs.length() > rhs.length())
            return rhs[0] < lhs[i];
        else
            return lhs[0] >= rhs[i];
        return 0;
    }*/
    
    static bool compare (const string& lhs, const string& rhs){
        string s1 = lhs + rhs;
        string s2 = rhs + lhs;
        return s2 < s1;
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
        
        string ret = Solution().largestNumber(nums);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
