//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort (A.begin(), A.end());
        int i = 0;
        while (i < A.size() && i < K && A[i] < 0){
            A[i] = -A[i];
            i++;
        }
        if (i < K)
            if ((K - i) & 1)
                if (i < A.size())
                    if (i == 0)
                        A[i] = -A[i];
                    else
                        if (A[i - 1] < A[i])
                            A[i - 1] = -A[i - 1];
                        else
                            A[i] = -A[i];
                else
                    A[A.size() - 1] *= -1;
                
        int s = 0;
        for (int i : A)
            s += i;
        return s;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        int K = stringToInteger(line);
        
        int ret = Solution().largestSumAfterKNegations(A, K);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
