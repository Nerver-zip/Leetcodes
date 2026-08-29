class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        vector<int> degree(n, 0);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 1){
                    ++degree[i];
                }
            }
        }

        return degree;
    }
};