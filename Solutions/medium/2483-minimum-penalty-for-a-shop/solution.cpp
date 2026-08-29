class Solution {
public:
    int bestClosingTime(string customers) {
        const int n = customers.size();
        vector<int> prefix_y(n+1, 0); // Sum of Y to the right 
        
        for (int i = n-1; i >= 0; --i) {
            if(customers[i] == 'Y')
                ++prefix_y[i];

            prefix_y[i] += prefix_y[i+1];
        }
        
        int n_count = 0, ans = INT32_MAX, minPenalty = INT32_MAX;
        
        // <= because hours -> [0, n]
        for (int i = 0; i <= customers.size(); ++i) {
            int currPenalty = n_count + prefix_y[i];
            
            if(currPenalty < minPenalty){
                minPenalty = currPenalty;
                ans = i;
            }
            
            if(i < n && customers[i] == 'N')
                ++n_count;
        }
        
        return ans;
    }
};