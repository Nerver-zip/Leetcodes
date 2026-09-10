constexpr int MOD = 1000000007; 
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int n = board.size();
    
        vector<vector<int>> dp1(n, vector<int>(n, -1)); // dp1[i][j] = maxSum you can reach at i,j
        vector<vector<int>> dp2(n, vector<int>(n, 0)); // dp2[i][j] = number of ways to reach i,j
        
        dp1[n-1][n-1] = 0;
        dp2[n-1][n-1] = 1;
        for(int i = n-2; i >= 0; --i){
            if(board[n-1][i] == 'X'){
                break;
            }
            else{
                dp1[n-1][i] = 0;
                dp1[n-1][i] += board[n-1][i] - '0' + dp1[n-1][i+1];

                dp2[n-1][i] += 1;
            }
        }

        for(int i = n-2; i >= 0; --i){
            if(board[i][n-1] == 'X'){
                break;
            }
            else{
                dp1[i][n-1] = 0;
                dp1[i][n-1] += board[i][n-1] - '0' + dp1[i+1][n-1];


                dp2[i][n-1] += 1;
            }
        }
        
        board[0][0] = '0';
        for(int i = n-2; i >= 0; --i){
            for(int j = n-2; j >= 0; --j){
                if(board[i][j] == 'X'){
                    continue;
                }

                if(dp1[i+1][j] != -1){
                    dp1[i][j] = max(dp1[i][j], dp1[i+1][j] + board[i][j] - '0');
                }
                
                if(dp1[i][j+1] != -1){
                    dp1[i][j] = max(dp1[i][j], dp1[i][j+1] + board[i][j] - '0');
                }

                if(dp1[i+1][j+1] != -1){
                    dp1[i][j] = max(dp1[i][j], dp1[i+1][j+1] + board[i][j] - '0');
                }

                int sum = dp1[i][j];

                if(board[i][j] - '0' + dp1[i+1][j] == sum){
                    dp2[i][j] = (dp2[i][j] + dp2[i+1][j]) % MOD;
                }
                if(board[i][j] - '0' + dp1[i][j+1] == sum){
                    dp2[i][j] = (dp2[i][j] + dp2[i][j+1]) % MOD;
                }
                if(board[i][j] - '0' + dp1[i+1][j+1] == sum){
                    dp2[i][j] = (dp2[i][j] + dp2[i+1][j+1]) % MOD;
                }
            }
        }
        
        return dp2[0][0] == 0 ? vector<int>{0,0} : vector<int>{dp1[0][0], dp2[0][0]};
    }
};