class EventManager {
public:
    EventManager(vector<vector<int>>& events) {
        for(const auto& event : events){
            pair<int,int> p = {event[0], event[1]};
            eventSet.insert(p);
            idToPair[event[0]] = p;
        } 
    }
    
    void updatePriority(int eventId, int newPriority) {
        auto it = eventSet.find(idToPair[eventId]);
        
        if(it != eventSet.end())
            eventSet.erase(it);
        
        pair<int,int> p = {eventId, newPriority};
        eventSet.insert(p);
        idToPair[eventId] = p; 
    }
    
    int pollHighest() {
        auto it = eventSet.begin();

        if(it != eventSet.end()){
            pair<int, int> p = *it;
            idToPair.erase(it->first);
            eventSet.erase(it);
            return p.first;
        }

        return -1; 
    }
private:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        }
    };
    
    set<pair<int,int>, Compare> eventSet;
    unordered_map<int, pair<int,int>> idToPair;
};