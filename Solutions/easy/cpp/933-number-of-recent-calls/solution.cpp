class RecentCounter {
private:
    std::queue<int> *recentCalls;
public:
    RecentCounter() {
        recentCalls = new std::queue<int>();
        recentCalls->push(-3000);
    }
    int ping(int t){
        recentCalls->push(t);
        while(abs(t - (recentCalls->front())) > 3000)
        {
            recentCalls->pop();
        }
        return recentCalls->size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */