class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        vector<int> dp(moves.size(), 0); // dp[i] = max distance from the origin until pos i 
        vector<int> dp2(moves.size(), 0); // dp2[i] = min distance from the origin until pos i

        if(moves[0] == 'R'){
            dp[0] = 1;
            dp2[0] = 1;
        }
        else if(moves[0] == 'L'){
            dp[0] = -1;
            dp2[0] = -1;
        }
        else{
            dp[0] = 1;
            dp2[0] = -1;
        }

        for(int i = 1; i < moves.size(); ++i){
            if(moves[i] == 'L'){
                dp[i] = dp[i-1] - 1;  
                dp2[i] = dp2[i-1] - 1;  
            }
            else if(moves[i] == 'R'){
                dp[i] = dp[i-1] + 1;  
                dp2[i] = dp2[i-1] + 1;  
            }
            else{
                dp[i] = dp[i-1] + 1;  
                dp2[i] = dp2[i-1] - 1;  
            }
        }

        return max(dp.back(), abs(dp2.back()));
    }
};