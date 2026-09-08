class ExamTracker {
public:
    ExamTracker() {
        prefix.push_back({0,0});
    }
    
    void record(int time, int score) {
        prefix.push_back({time, prefix.back().second + score});
    }
    
    long long totalScore(int startTime, int endTime) {
        int it1 = lower_bound(startTime);
        int it2 = lower_bound(endTime);

        if(prefix[it1].first > endTime || prefix[it2].first < startTime)
            return 0;

        if(prefix[it2].first > endTime)
            --it2;
        
        return prefix[it2].second - prefix[it1-1].second;
    }
private:
    vector<pair<int, long long>> prefix; //{time, total sum}
    int lastTime = 0;

    int lower_bound(int time){
        int left = 0;
        int right = prefix.size()-1;
        int i = 0;
        while (left <= right) {
            int mid = left + (right-left)/2;

            if(prefix[mid].first >= time){
                i = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return i;
    }
};