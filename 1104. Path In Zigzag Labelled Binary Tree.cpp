//https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> temp;
        int pow2 = 1;
        while (label / pow2 != 1)
            pow2 *= 2;
        while (label - 1){
            temp.insert(temp.begin(),label);
            label /= 2;
            pow2 /= 2;
            label = (pow2 * 2 - 1) + pow2 - label;
        }
        temp.insert(temp.begin(),1);
        return temp;
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
        int label = stringToInteger(line);
        
        vector<int> ret = Solution().pathInZigZagTree(label);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
