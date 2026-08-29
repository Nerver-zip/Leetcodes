class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<int> rows(m), cols(n);

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 1){
                    ++rows[i];
                    ++cols[j];
                }

        int ans = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
                    ++ans;
        return ans;
    }           
};