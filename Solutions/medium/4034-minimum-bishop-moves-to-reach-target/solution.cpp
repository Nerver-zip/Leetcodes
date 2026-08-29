class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        // opposite color

        if((source[0] + source[1]) % 2 != (target[0] + target[1]) % 2){
            return -1;
        }

        int distX = abs(source[0] - target[0]) + 1;
        int distY = abs(source[1] - target[1]) + 1;
        
        return distX == distY ? 1 : 2;
    }
};