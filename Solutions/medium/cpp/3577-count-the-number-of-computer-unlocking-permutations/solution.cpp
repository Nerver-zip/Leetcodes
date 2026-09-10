using ll = long long;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int minimum = *min_element(complexity.begin(), complexity.end());
        
        for (int i = 1; i < complexity.size(); ++i) {
            if(minimum == complexity[i])
                return 0;
        }

        if(complexity[0] != minimum)
            return 0;

        return fatorial(complexity.size() - 1); 
    }
private:
    const int MOD = 1e9 + 7;
    ll fatorial(ll n){
        if(n == 0 || n == 1)
            return 1;
        return n * fatorial(n-1) % MOD;
    }
};