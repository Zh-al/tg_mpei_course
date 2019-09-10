//https://leetcode.com/problems/2-keys-keyboard/

//ищем делители и для каждого надо выполнить скопировать + вставить (*делитель* - 1 раз) => *делитель* действий
class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        int i = 2;
        while (n != 1)
            {
                if (n % i == 0)
                {
                    count += i;
                    n = n / i;
                }
                else
                {
                    i += 1;
                }
            }
        return count;
    }
};
