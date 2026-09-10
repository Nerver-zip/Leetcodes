class Solution {
private: 
    long long dfs(const vector<vector<int>>& questions, vector<long long>& cache, int index){
        if (index >= questions.size())
        {
            return 0;
        }
        if (cache[index])
        {
            return cache[index];
        }
        else
        {
            //Max between skipping and adding 0 points and skipping BP and adding currPoints
            cache[index] = std::max( 
            dfs(questions, cache, index+1), questions[index][0] + dfs(questions, cache, index + questions[index][1] + 1)
            );
        }
        return cache[index];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> cache(questions.size(), 0);
        return dfs(questions, cache, 0);
    }
};