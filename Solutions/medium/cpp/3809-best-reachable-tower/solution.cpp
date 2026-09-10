class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans = {INT_MAX, INT_MAX};
        int maxQuality = 0;

        int cx = center[0], cy = center[1];

        for (const auto& tower : towers) {
            int x = tower[0], y = tower[1], c = tower[2]; 
            
            if(abs(cx - x) + abs(cy - y) <= radius){
                if(c > maxQuality){
                    ans[0] = x;
                    ans[1] = y;
                    maxQuality = c;
                }
                else if(c == maxQuality){
                    if(x < ans[0] || (x == ans[0] && y < ans[1])){
                        ans[0] = x;
                        ans[1] = y;
                    }
                }
            }
        }

        if(ans[0] == INT_MAX){
            vector<int> excpt = {-1,-1};
            return excpt;
        }

        return ans;
    }
};