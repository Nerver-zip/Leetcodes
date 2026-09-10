class Solution {
private:
    int dfs(const vector<int>& days, const vector<int>& costs, vector<int>& memo, int index){
        if(index >= days.size())
            return 0;
        if(memo[index] != -1)
            return memo[index];
        int option1 = dfs(days, costs, memo, index + 1) + costs[0];
        
        int option2 = INT32_MAX;
        int lastDay_7 = days[index] + 7;
        int i = index;
        while(i < days.size() && days[i] < lastDay_7) 
            ++i;
        option2 = dfs(days ,costs, memo, i) + costs[1];
        
        int option3 = INT32_MAX;
        int lastDay_30 = days[index] + 30;
        i = index;
        while (i < days.size() && days[i] < lastDay_30)
            ++i;
        option3 = dfs(days, costs, memo, i) + costs[2];

        memo[index] = min({option1, option2, option3});
        return memo[index];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        memo[0] = dfs(days, costs, memo, 0);
        return memo[0];
    }
};