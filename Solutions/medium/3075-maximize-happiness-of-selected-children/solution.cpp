using ll = long long;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](const auto& a, const auto& b){return a > b;});
        
        ll sum = 0;
        for (int i = 0; i < k; ++i) {
            ll curr = happiness[i] - i;
            if(curr > 0)
                sum += curr;
        }

        return sum;
    }
};
