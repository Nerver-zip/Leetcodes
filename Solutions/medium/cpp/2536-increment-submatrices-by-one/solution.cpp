class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {    
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for(const auto& query : queries){
            int r1 = query[0], c1 = query[1],
            r2 = query[2], c2 = query[3] + 1;
            
            for (int i = r1; i <= r2; ++i) {
                ++matrix[i][c1];
                if(c2 == n)
                    continue;
                --matrix[i][c2];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j-1]; 
            }
        }

        return matrix;
    }
};