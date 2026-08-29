class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        ranges::sort(prices, greater{});
        ranges::sort(discounts, greater{});

        // (p * (100 - d)) / 100);
    
        double sum = 0.0;
        
        int i = 0;
        for(double p : prices){
            if(i < discounts.size()){
                p = (p * (100 - discounts[i]) / 100.0);
            }
            sum += p;
            ++i;
        }

        return sum;
    }
};