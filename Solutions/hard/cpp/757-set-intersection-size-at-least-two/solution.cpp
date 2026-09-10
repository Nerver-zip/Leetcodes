class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        // Ordena por fim crescente, em caso de empate, maior começo
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
        });
        
        int a = -1, b = -1, ans = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if(b < intervals[i][0]){
                a = intervals[i][1] - 1;
                b = intervals[i][1];
                ans += 2;
            }
            else if(a < intervals[i][0]){
                a = b;
                b = intervals[i][1];
                ++ans;
            }
        }

        return ans;
    }
};