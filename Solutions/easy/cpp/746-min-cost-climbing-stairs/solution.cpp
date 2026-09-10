class Solution {
private:
    int solve(const vector<int>& cost, vector<int>& memo, int i){
        if(i >= cost.size())
            return 0;
        if(memo[i] != -1)
            return memo[i];
        memo[i] = min(solve(cost, memo, i+1) + cost[i], solve(cost, memo, i+2) + cost[i]);
        return memo[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size()+1, -1);
        memo[0] = solve(cost, memo, 0);
        return min(memo[0], memo[1]);
    }
};