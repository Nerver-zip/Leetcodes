class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int size = startTime.size();

        vector<pair<int,int>> meetings(size);//{leftGapSize, rightGapSize}
        multiset<int> gaps;
        int gap;
        int j = 0;

        if(startTime[0] == 0){
            meetings[0] = {0,0};
            ++j;
        }
        
        if(startTime[0] != 0){
            gaps.insert(startTime[0]);
            meetings[0] = {startTime[0], 0};
            ++j;
        }
        for (int i = 1; i < size; ++i){
            gap = startTime[i] - endTime[i - 1];
            if(j > 0)
                meetings[j-1].second = gap;
            gaps.insert(gap);
            meetings[j] = {gap, 0};
            ++j;
        }
        
        if(endTime[size-1] != eventTime){
            gaps.insert(eventTime - endTime[size-1]);
            meetings[j-1].second = eventTime - endTime[size-1];
        }

        int ans = 0;
        for (int i = 0; i < size; ++i)
        {
            int start = startTime[i], end = endTime[i];
            int duration = end - start, leftGap = meetings[i].first, rightGap = meetings[i].second;

            //First try to shift the meeting towards another, the same as the sum of left and right gap
            ans = max(ans, leftGap + rightGap);

            //Then check if its possible to delete it (ideal)
            //That is equal to the meeting size + left gap + right gap
            auto itL = gaps.find(leftGap);
            bool placeBackL = false;
            //Remove adjacent gaps
            if(itL != gaps.end()){
                placeBackL = true;
                gaps.erase(itL);
            }

            auto itR = gaps.find(rightGap);
            bool placeBackR = false;
            if(itR != gaps.end()){
                placeBackR = true;
                gaps.erase(itR);
            }

            //Scan for somewhere to place meeting
            auto it = gaps.lower_bound(duration);

            if(it != gaps.end())
                ans = max(ans, leftGap + rightGap + duration);

            if(placeBackL)
                gaps.insert(leftGap);
            if(placeBackR)
                gaps.insert(rightGap);
        }
        return ans;
    }
};