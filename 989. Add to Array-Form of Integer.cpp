//https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int temp = K;
        int i = (int)A.size() - 1;
        vector <int> res;
        while (i >= 0 || temp)
        {
            if (i >= 0)
                temp += A[i];
            res.push_back (temp % 10);
            temp /= 10;
            i--;
        }
        int n = res.size();
        for (int i = 0; i < n / 2; i++)
            swap (res[i], res[n - i - 1]);
        return res;
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
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        vector<int> ret = Solution().addToArrayForm(A, K);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
