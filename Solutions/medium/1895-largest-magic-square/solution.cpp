class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();

        vector<vector<int>> prefixRow(n, vector<int>(m, 0));
        vector<vector<int>> prefixCol(n, vector<int>(m, 0));
        
        // init prefix rows
        for (int i = 0; i < n; ++i) {
            prefixRow[i][0] = grid[i][0];
        }
        
        // init prefix cols
        for (int i = 0; i < m; ++i) {
            prefixCol[0][i] = grid[0][i];
        }

        //build prefix rows
            
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                prefixRow[i][j] += prefixRow[i][j-1] + grid[i][j];
            }
        }

        //build prefix cols    
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                prefixCol[i][j] += prefixCol[i-1][j] + grid[i][j];
            }
        }
        
        int ans = 1;

        auto check = [&](int r, int c) {
            for (int side = 0; r + side < n && c + side < m; ++side) {

                unordered_set<int> s;

                // linhas
                for (int i = 0; i <= side; ++i) {
                    int sumRow = prefixRow[r + i][c + side] 
                               - (c > 0 ? prefixRow[r + i][c - 1] : 0);
                    s.insert(sumRow);
                    if (s.size() > 1) break;
                }
                
                if (s.size() > 1) continue;

                // colunas
                for (int i = 0; i <= side; ++i) {
                    int sumCol = prefixCol[r + side][c + i]
                               - (r > 0 ? prefixCol[r - 1][c + i] : 0);
                    s.insert(sumCol);
                    if (s.size() > 1) break;
                }
                if (s.size() > 1) continue;

                // diagonais
                int mainDiag = 0, secDiag = 0;
                for (int i = 0; i <= side; ++i) {
                    mainDiag += grid[r + i][c + i];
                    secDiag += grid[r + i][c + side - i];
                }

                s.insert(mainDiag);
                s.insert(secDiag);

                if (s.size() == 1)
                    ans = max(ans, side + 1);
            }
        };

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                check(i, j);

        return ans;
    }
};