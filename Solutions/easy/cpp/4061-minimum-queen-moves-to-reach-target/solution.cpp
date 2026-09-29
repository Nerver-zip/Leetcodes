class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source == target){
            return 0;
        }

        if(source[0] == target[0] || source[1] == target[1]){
            return 1;
        }

        int distX = abs(source[0] - target[0]) + 1;
        int distY = abs(source[1] - target[1]) + 1;
    
        return distX == distY ? 1 : 2;
    }
};