class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        
        int ans = 0;

        while(!cost.empty()){
            ans += cost.back();
            cost.pop_back();
            
            if(!cost.empty()){
                ans += cost.back();
                cost.pop_back();
            }

            if(!cost.empty())
                cost.pop_back();
        }

        return ans;
    }
};