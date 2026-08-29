class Router {
private:
    queue<tuple<vector<int>, string>> q;
    unordered_set<string> seen;
    unordered_map<int, pair<int,vector<int>>> destToTimestamp; //destination -> timestamps
    int limit;

    int binarySearchUpper(const vector<int>& nums, int left, int target){
        int right = nums.size()-1, ans = -1;

        while (left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] <= target){
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }

    int binarySearchLower(const vector<int>& nums, int left, int target){
        int right = nums.size()-1, ans = -1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if(nums[mid] >= target){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "," + to_string(destination) + "," + to_string(timestamp);

        if(seen.count(key))
            return false;
        
        auto& [_, packages] = destToTimestamp[destination];
        
        if(q.size() == limit){
            auto [packet, key] = q.front(); 
            q.pop();
            seen.erase(key);
            auto& [left,_] = destToTimestamp[packet[1]];
            ++left; //deque
        }

        seen.insert(key);

        q.push({{source, destination, timestamp}, key});
        packages.push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty())
            return {};

        auto [packet, key] = q.front();
        seen.erase(key);
        q.pop();
        
        auto& [left, _] = destToTimestamp[packet[1]];
        ++left;
        
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto left = destToTimestamp[destination].first;
        const auto& nums = destToTimestamp[destination].second;
        
        if(left >= nums.size())
            return 0;
        
        auto low = binarySearchLower(nums, left, startTime);
        auto high = binarySearchUpper(nums,  left, endTime);
        
        return low < 0 || high < 0 ? 0 : high - low + 1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */