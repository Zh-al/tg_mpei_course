//https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int N) {
        int last = -1, ans = 0;
        for (int i = 0; i < 32; i++)
            if ((N >> i) & 1) {
                if (last >= 0)
                    ans = max(ans, i - last);
                last = i;
            }

        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);
        
        int ret = Solution().binaryGap(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
