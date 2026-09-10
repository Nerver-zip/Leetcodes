class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        combinate(1, res, n, k);
        return combinations;
    }

private:
    vector<vector<int>> combinations;
    
    void combinate(int n, vector<int>& res, const int N, const int K){
        if(res.size() == K)
            combinations.push_back(res);
        for(int i = n; i <= N; ++i){
            res.push_back(i);
            combinate(i+1, res, N, K);
            res.pop_back();
        }
    }
};