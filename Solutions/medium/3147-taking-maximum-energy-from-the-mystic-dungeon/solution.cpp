class Solution {
private:
    int dfs(const vector<int>& energy, vector<int>& memo, int k, int index){
        if(index >= energy.size())
            return 0;
        if(memo[index] != -1)
            return memo[index];
        
        return memo[index] = energy[index] + dfs(energy, memo, k, index+k);
    }
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> memo(energy.size(),-1); //memo[i] = maximumEnergy starting from index i
        
        int maxEnergy = INT_MIN;

        for (int i = 0; i < energy.size(); ++i)
            maxEnergy = max(maxEnergy, dfs(energy, memo, k, i));

        return maxEnergy;
    }
};