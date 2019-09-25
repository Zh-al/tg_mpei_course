//https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort (temp.begin(),temp.end());
        int count = 0;
        for (size_t i = 0; i < temp.size(); ++i)
            if (temp[i] != heights[i])
                count++;
        return count;
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
        vector<int> heights = stringToIntegerVector(line);
        
        int ret = Solution().heightChecker(heights);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
