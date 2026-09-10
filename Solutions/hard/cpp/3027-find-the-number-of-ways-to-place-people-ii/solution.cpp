class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; // smaller x, untie greater y
        });

        int ans = 0;

        for (int i = 0; i < points.size()-1; ++i) {
            int bottomRightY = INT32_MIN;
            for (int j = i + 1; j < points.size(); ++j) {
                if(points[i][1] >= points[j][1] && bottomRightY < points[j][1]){
                    ++ans;
                    bottomRightY = points[j][1];
                }
            }
        }
        return ans;
    }
};