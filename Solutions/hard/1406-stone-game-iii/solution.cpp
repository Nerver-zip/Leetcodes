// memo[i] = max difference between Alice and Bob at the index i
class Solution {
private:
    int minimax(const vector<int>& stoneValue, vector<int>& memo, int i){
        if(i >= stoneValue.size())
            return 0;

        if(memo[i] != numeric_limits<int>::min())
            return memo[i];
        
        int res = 0;
        for(int take = 0; take < 3 && take + i < stoneValue.size(); ++take){
            res += stoneValue[i + take];
            memo[i] = max(memo[i], res - minimax(stoneValue, memo, i + take + 1));
        }
        
        return memo[i];
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> memo(n, numeric_limits<int>::min());
        int res = minimax(stoneValue, memo, 0);
        
        return res == 0 ? "Tie" :
               res < 0 ? "Bob" :
               "Alice";
    }
};