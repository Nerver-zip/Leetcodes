class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int x = points[0][0], y = points[0][1];
        
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            int next_x = points[i][0], next_y = points[i][1];
        
            // First travel diagonally as far as possible
            // min(abs(x - next_x), abs(y - next_y))

            int diagDist = min(abs(x - next_x), abs(y - next_y));
            
            x = next_x < x ? x - diagDist : x + diagDist;
            y = next_y < y ? y - diagDist : y + diagDist;
            ans += diagDist;
            
            //Then travel in a straight line to complete 
            int straightDist = max(abs(x - next_x), abs(y - next_y));
            x = next_x < x ? x - straightDist : x + straightDist;
            y = next_y < y ? y - straightDist : y + straightDist;
            ans += straightDist;
            
            x = next_x;
            y = next_y;
        }

        return ans;
    }
};