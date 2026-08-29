using ll = long long;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<int> heights(n, 0);
        
        int ans = 0;
        for(int i = 0; i < m; ++i){

            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 1)
                    ++heights[j];
                else
                    heights[j] = 0;
            }

            vector<int> sorted = heights;
            sort(sorted.rbegin(), sorted.rend());

            for(int k = 0; k < n; ++k)
                ans = max(ans, sorted[k] * (k + 1));
        }

        return ans;
    }
};