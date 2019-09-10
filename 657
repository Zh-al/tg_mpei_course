//https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        short int x = 0;
        short int y = 0;
        for (unsigned short int i = 0; i < moves.length(); ++i)
        {
            if (moves[i] == 'U')
                y += 1;
            else if (moves[i] == 'D')
                y -= 1;
            else if (moves[i] == 'L')
                x -= 1;
            else
                x += 1;
            
        }
        if (x == 0 && y == 0)
            return 1;
        else
            return 0;
    }
};
