class RideSharingSystem {
public:
    RideSharingSystem() {
        time = 0;
    }
    
    void addRider(int riderId) {
        ++time;
        riders.insert({time, riderId});
        idToPair[riderId] = {time, riderId};
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(riders.empty() || drivers.empty())
            return {-1,-1};
        
        auto it = riders.cbegin();
        vector<int> match = {drivers.front(), it->second};

        riders.erase(it);
        drivers.pop();
        
        return match;
    }
    
    void cancelRider(int riderId) {
        pair<int,int> p = idToPair[riderId];
        
        auto it = riders.find(p);
        if(it != riders.end())
            riders.erase(it);
    }
private:
    set<pair<int,int>> riders; // {time, id}
    unordered_map<int, pair<int,int>> idToPair;
    queue<int> drivers;
    int time;
};