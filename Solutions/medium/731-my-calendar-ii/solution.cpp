class MyCalendarTwo {
private:
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> doubleBookings;

    bool doesOverlap(int x1, int x2, int y1, int y2){
        return std::max(x1, y1) < std::min(x2, y2);
    }

    pair<int,int> getOverlapInterval(int x1, int x2, int y1, int y2){
        pair<int, int> interval;
        interval.first = std::max(x1, y1);
        interval.second = std::min(x2, y2);
        return interval;
    }

public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for (const auto& [start, end] : doubleBookings)
        {
            if(doesOverlap(startTime, endTime, start, end))
                return false;
        }
        
        for (const auto& [start, end] : bookings)
        {
            if (doesOverlap(startTime, endTime, start, end))
            {
                doubleBookings.push_back(getOverlapInterval(startTime, endTime, start, end));
            }
        }
        bookings.push_back({startTime, endTime});
        return true;
    }
};
