class SummaryRanges {
public:
    // At most 100 calls will be made to getIntervals so it should still pass

    SummaryRanges() {
        fill(numbers.begin(), numbers.end(), false);
    }
    
    void addNum(int value) {
        numbers[value] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        int a = -1, b = -1;
        
        for(int i = 0; i < MAX_SIZE; ++i){
            if(a == -1 && numbers[i])
                a = b = i;
            else if(a != -1 && numbers[i])
                b = i;
            else if(a != -1 && !numbers[i]){
                ans.push_back({a,b});
                a = -1;
                b = -1;
            }
        }



        return ans;
    }


private:
    // 10002 so the state machine can handle the case where 
    // the interval is [10000, 10000]
    static constexpr int MAX_SIZE = 10002;
    array<bool, MAX_SIZE> numbers;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */