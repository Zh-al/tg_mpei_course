//https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map <int,int> m;
        for (int i : bills)
            if (i == 5)
                m[i]++;
            else if (i == 10){
                m[i]++;
                if (m[5] == 0)
                    return false;
                else
                    m[5]--;
            }
            else{
                if (m[10] > 0 && m[5] > 0){
                    m[10]--;
                    m[5]--;
                }
                else if (m[5] >= 3)
                    m[5] -= 3;
                else
                    return false;
            }
        return true;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> bills = stringToIntegerVector(line);
        
        bool ret = Solution().lemonadeChange(bills);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
