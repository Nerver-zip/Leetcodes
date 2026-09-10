class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
         sort(hBars.begin(), hBars.end());
         sort(vBars.begin(), vBars.end());

        int hDist = 0;
        int currDist = 0;
        for (int i = 1; i < hBars.size(); ++i) {
            if(hBars[i-1] == hBars[i] - 1){
                ++currDist;
                hDist = max(currDist, hDist);
            }
            else {
                currDist = 0;   
            }
        }
        
        int vDist = 0;
        currDist = 0;
        for (int i = 1; i < vBars.size(); ++i) {
            if(vBars[i-1] == vBars[i] - 1){
                ++currDist;
                vDist = max(currDist, vDist);
            }
            else {
                currDist = 0;   
            }
        }
        
        return min(hDist + 2, vDist + 2) * min(hDist + 2, vDist + 2);
    }
};