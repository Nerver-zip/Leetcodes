class Solution {
private:
    void getIntervalsXY(const vector<vector<int>>& intervals, vector<vector<int>>& mergedIntervalsX, vector<vector<int>>& mergedIntervalsY) {
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> minHeapX;
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, std::greater<>> minHeapY;

    for (const auto& interval : intervals)
    {
        minHeapX.push({interval[0],interval[2]});
        minHeapY.push({interval[1],interval[3]});
    }
    
    auto [left, right] = minHeapX.top();
    while (!minHeapX.empty())
    {
        auto [currLeft, currRight] = minHeapX.top();
        minHeapX.pop();
        if (currLeft >= right)
        {
            mergedIntervalsX.push_back({left, right});
            left = currLeft;
        }
        right = currRight > right ? currRight : right;
        if(minHeapX.empty()){
            mergedIntervalsX.push_back({left, right});
        } 
    }

    left = minHeapY.top().first;
    right = minHeapY.top().second;
    
    while (!minHeapY.empty())
    {
        auto [currLeft, currRight] = minHeapY.top();
        minHeapY.pop();
        if (currLeft >= right)
        {
            mergedIntervalsY.push_back({left, right});
            left = currLeft;
        }
        right = currRight > right ? currRight : right;
        if(minHeapY.empty()){
            mergedIntervalsY.push_back({left, right});
        } 
    }
}
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> mergedIntervalX;
        vector<vector<int>> mergedIntervalY;

        getIntervalsXY(rectangles, mergedIntervalX, mergedIntervalY);

        return mergedIntervalX.size() > 2 || mergedIntervalY.size() > 2;
    }
};