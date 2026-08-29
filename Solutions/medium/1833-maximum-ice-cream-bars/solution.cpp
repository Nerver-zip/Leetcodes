class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(1e5 + 1, 0);
        
        int mx = 0;
        for(int c : costs){
            mx = max(mx, c);
            ++freq[c];
        }

        vector<int> sorted;
        sorted.reserve(costs.size());

        for(int i = 0; i <= mx; ++i)
            while(freq[i]--)
                sorted.push_back(i);
        
        int ans = 0;

        for(int i = 0; i < sorted.size(); ++i){
            if(coins >= sorted[i]){
                coins -= sorted[i];
                ++ans;
            }
            else
                break;
        }

        return ans;
    }
};