class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // try starting iwth landrides, then try starting with water rides
        
        const int n = landStartTime.size();
        const int m = waterStartTime.size();

        int startLand = numeric_limits<int>::max();
        for(int i = 0; i < n; ++i){
            startLand = min(startLand, landStartTime[i] + landDuration[i]);
        }

        int startWater = numeric_limits<int>::max();
        for(int j = 0; j < m; ++j){
            startWater = min(startWater, waterStartTime[j] + waterDuration[j]);
        }
        
        // Notice that we will be forced to add something to both startLand and startWater.
        // if they are greater then start times, just add the minimum duration to its counter part
        // otherwise, add startTime + duration
        
        int addToLand = numeric_limits<int>::max();
        for(int j = 0; j < m; ++j){
            addToLand = min(addToLand, max(0, waterStartTime[j] - startLand) + waterDuration[j]);
        }

        int addToWater = numeric_limits<int>::max();
        for(int i = 0; i < n; ++i){
            addToWater = min(addToWater, max(0, landStartTime[i] - startWater) + landDuration[i]);
        }

        return min(startLand + addToLand, startWater + addToWater);
    }
};