class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        ranges::sort(lights);
        
        int ans = 0;
        for(int time : arrivalTime){
            int r = time % period;
            
            auto ub = ranges::upper_bound(lights, r+1);
            
            if(ub == lights.end()){
                ub = lights.end()-1;
            }

            int waitingTime = 0;

            if(r >= *ub){
                waitingTime = period - r;
            }
            
            ans = max(ans, waitingTime);
        }

        return ans;
    }
};