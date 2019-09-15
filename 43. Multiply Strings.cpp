//https://leetcode.com/problems/multiply-strings/submissions/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int length1 = num1.length();
        int length2 = num2.length();
        int numbers [length2 + length1 + 1];
        int temp;
        int difference = int('0');
        for (int i = 0; i < length2 + length1 + 1; ++i)
            numbers [i] = 0;
        for (int i = length2 - 1; i >= 0; --i)
        {
            for (int j = length1 - 1; j >= 0; --j)
            {
                temp = (int (num2[i]) - difference) * (int (num1[j]) - difference);
                numbers [i + j + 2] += temp % 10; 
                numbers [i + j + 2 - 1] += temp / 10;
            }
        }
        string result;
        for (int i = length2 + length1; i >= 0; --i)
        {
            if (numbers [i] > 9 && i != 0)
            {
                numbers [i - 1] += numbers [i] / 10;
                numbers [i] %= 10;   
            }
            result.insert (result.begin(), char (numbers[i] + difference));
        }
        while (result[0] == '0')
            result.erase (0,1);
        return result;
    }
};
