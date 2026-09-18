class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int X1 = rec2[0], Y1 = rec2[1], X2 = rec2[2], Y2 = rec2[3];
   
        if(x1 >= X2 || y1 >= Y2 || x2 <= X1 || y2 <= Y1){
            return false;
        }

        return true;
    }
};