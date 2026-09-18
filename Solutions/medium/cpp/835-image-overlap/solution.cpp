class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        
        int ans = 0;
        for(int dx = -(n-1); dx <= n-1; ++dx){
            for(int dy = -(n-1); dy <= n-1; ++dy){
                
                int res = 0;
                
                for(int i = 0; i < n; ++i){
                    for(int j = 0; j < n; ++j){
                        
                        int ni = i + dx;
                        int nj = j + dy;

                        if(ni < 0 || nj < 0 || ni >= n || nj >= n){
                            continue;
                        }

                        if(img1[ni][nj] && img2[i][j]){
                            ++res;
                        }

                    }
                }

                ans = max(ans, res);
            }
        }

        return ans;
    }
};