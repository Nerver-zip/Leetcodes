class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minimum = INT64_MAX;
        if(costBoth < cost1 && costBoth < cost2){
            cout << "Here" << "\n";
            minimum = min(minimum, 1LL * costBoth * max(need1, need2));
        }
        
        if(need2 - need1 <= 0){
            cout << "Here2" << "\n";
            minimum = min(minimum, 1LL * costBoth * need1);
        }
        
        if(need1 - need2 <= 0){
            cout << "Here3" << "\n";
            minimum = min(minimum, 1LL * costBoth * need2);
        }

        if(need1 < need2){
            cout << "Here4" << "\n";
            minimum = min(minimum, 1LL * costBoth * need1 + 1LL * cost2 * (need2-need1));
        }

        if(need2 < need1){
            cout << "Here5" << "\n";
            minimum = min(minimum, 1LL * costBoth * need2 + 1LL * cost1 * (need1-need2));
        }

        minimum = min(minimum, 1LL * cost1 * need1 + 1LL * cost2 * need2);

        return minimum;
    }
};