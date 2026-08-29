class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0;
        
        int count = 0;

        for(char c : moves){
            if(c == '_')
                ++count;
            else if(c == 'U')
                ++y;
            else if(c == 'D')
                --y;
            else if(c == 'L')
                --x;
            else
                ++x;
        }
        
        return max({abs(x + count) + abs(y),
                    abs(x - count) + abs(y),
                    abs(x) + abs(y + count),
                    abs(x) + abs(y - count)});
    }
};