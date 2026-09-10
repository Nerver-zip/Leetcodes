class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1]; // biggest y, then smallest x
        });

        int ans = 0;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                // A upper left as seen from B
                if(x1 <= x2 && y1 >= y2){
                    bool valid = true;
                    
                    //Checks for points unvalidating pair
                    for (int k = 0; k < points.size(); ++k) {
                        if(i == k || j == k)
                            continue;
                        int x3 = points[k][0], y3 = points[k][1];

                        if(x3 >= x1 && x3 <= x2 && y3 >= y2 && y3 <= y1){
                            valid = false;
                            break;
                        }
                    }                         
                    if(valid)
                        ++ans;
                }
            }
        }
        return ans;
    }
};
