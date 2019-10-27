//https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1 = m + n - 1, j = n - 1, i = m - 1;
        while (i >= 0 || j >= 0){
            int val1 = i < 0 ? INT_MIN : nums1[i];
            int val2 = j < 0 ? INT_MIN : nums2[j];
            if (val1 > val2){
                nums1[ind1--] = val1;
                i--;
            }
            else{
                nums1[ind1--] = val2;
                j--;
            }
        }
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        Solution().merge(nums1, m, nums2, n);

        string out = integerVectorToString(nums1);
        cout << out << endl;
    }
    return 0;
}
