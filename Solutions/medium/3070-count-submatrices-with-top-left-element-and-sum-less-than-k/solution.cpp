class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();

        
        vector<vector<int>> prefixCol(2, vector<int>(n, 0)); // [0][j] prefixo col anterior 
                                                     // [1][j] prefix col atual
        vector<int> prefixRow(n, 0); 

        int ans = 0;
        for(int i = 0; i < m; ++i){
            
            prefixRow[0] = grid[i][0]; // builda pref row

            prefixCol[1][0] = prefixCol[0][0] + prefixRow[0]; // prefixCol eh feita somando prefRow atual + pref col anterior 
            
            if(prefixCol[1][0] <= k)
                ++ans;

            prefixCol[0][0] = prefixCol[1][0]; // salva

            for(int j = 1; j < n; ++j){
                prefixRow[j] = prefixRow[j-1] + grid[i][j]; // builda pref row
                prefixCol[1][j] = prefixCol[0][j] + prefixRow[j]; // prefixCol eh feita somando prefRow atual + pref col anterior 

                prefixCol[0][j] = prefixCol[1][j]; // Salva
                
                if(prefixCol[1][j] <= k)
                    ++ans;
            }
        }

        return ans;
    }
};