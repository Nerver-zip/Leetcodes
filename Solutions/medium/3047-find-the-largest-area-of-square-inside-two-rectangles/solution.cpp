using ll = long long;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        const int n = bottomLeft.size();
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev_bottomX = bottomLeft[i][0];
            int prev_bottomY = bottomLeft[i][1];
            int prev_TopX    = topRight[i][0];
            int prev_topY    = topRight[i][1];

            for (int j = i + 1; j < n; ++j) {
                int curr_bottomX = bottomLeft[j][0];
                int curr_bottomY = bottomLeft[j][1];
                int curr_topX    = topRight[j][0];
                int curr_topY    = topRight[j][1];

                // não sobrepõem
                if (curr_bottomX >= prev_TopX || prev_bottomX >= curr_topX ||
                    curr_bottomY >= prev_topY || prev_bottomY >= curr_topY)
                    continue;

                // interseção
                int interX1 = max(prev_bottomX, curr_bottomX);
                int interY1 = max(prev_bottomY, curr_bottomY);
                int interX2 = min(prev_TopX, curr_topX);
                int interY2 = min(prev_topY, curr_topY);

                ll squareSide = min(interX2 - interX1, interY2 - interY1);
                ans = max(ans, squareSide * squareSide);
            }
        }
        return ans;
    }
};