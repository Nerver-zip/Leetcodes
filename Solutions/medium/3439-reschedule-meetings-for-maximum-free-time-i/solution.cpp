
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int meetings = startTime.size();
        vector<int> gaps(meetings+1);

        gaps[0] = startTime[0];
        for (int i = 1; i < meetings; ++i) 
            gaps[i] = startTime[i] - endTime[i - 1];
        gaps[meetings] = eventTime - endTime[meetings-1];

        int right = 0, windowSize = k+1, maxFreeTime = 0, left = 0, ans = 0;
        for (right; right < gaps.size(); ++right)
        {   
            maxFreeTime += gaps[right];
            int size = right - left + 1;
            if(size > windowSize){
                maxFreeTime -= gaps[left];
                left++;
            }
            ans = max(ans, maxFreeTime);
        }
        return ans;
    }
};