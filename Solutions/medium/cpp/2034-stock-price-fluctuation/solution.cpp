#define INF_MIN 0
class StockPrice {
private:
    std::unordered_map<int,int> timeMap; //time, val
    std::map<int,int> stock; //price, freq
    int time = INF_MIN;
public:
    StockPrice() {
        
    }

    void update(int timestamp, int price) {
        if (timestamp > time)
            time = timestamp;
        if (timeMap.find(timestamp) != timeMap.end())
        {
            int currPrice = timeMap[timestamp];
            
            if (stock[currPrice] > 1)
                stock[currPrice]--;
            else
                stock.erase(currPrice);
        }
        timeMap[timestamp] = price;
        stock[price]++;
    }
    
    int current() {
        return timeMap[time];
    }
    
    int maximum() {
        return stock.rbegin()->first;
    }
    
    int minimum() {
        return stock.begin()->first;
    }
};