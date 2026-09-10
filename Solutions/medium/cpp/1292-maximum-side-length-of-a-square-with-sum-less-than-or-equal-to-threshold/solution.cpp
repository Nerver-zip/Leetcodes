class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n+1, 0));
        // rectangle sum from (0,0) to (i-1, j-1)
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefix[i+1][j+1] = 
                      prefix[i][j+1]
                    + prefix[i+1][j]
                    - prefix[i][j]
                    + mat[i][j];
            }
        }
        
        
        auto check = [&](int side){
            for (int i = 0; i + side <= m; ++i) {
                for (int j = 0; j + side <= n; ++j) {
                    int sum =
                        prefix[i+side][j+side]
                      - prefix[i][j+side]
                      - prefix[i+side][j]
                      + prefix[i][j];                
                    
                    if(sum <= threshold)
                        return true;
                }
            }
            return false;
        };

        int left = 1, right = min(m,n), ans = 0;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            if(check(mid)){
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return ans;
    }
};