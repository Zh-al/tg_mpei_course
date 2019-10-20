//https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> past {1};      
        for (int i = 1; i <= rowIndex; i++){
            vector <int> row;
            row.push_back (1);
            for (int j = 1; j < i; j++)
                row.push_back (past[j - 1] + past[j]);
            row.push_back(1);
            past = row;
        }
        return past;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int rowIndex = stringToInteger(line);
        
        vector<int> ret = Solution().getRow(rowIndex);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
