class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        auto it = map.find(key);
        
        if(it == map.end()){
            if(linkedList.empty() || linkedList.front().first != 1){
                linkedList.push_front({1, {}});
            }
            linkedList.front().second.insert(key);
            map[key] = linkedList.begin();
            return;
        }

        auto listIt = it->second;
        auto& [freq, set] = *listIt;

        // We need to insert into neigh
        auto it_nxt = std::next(listIt);
        
        // If it doesnt exist or it's not a neigh freq, create entry
        if(it_nxt == linkedList.end() || it_nxt->first > freq + 1){
            auto newIt = linkedList.insert(it_nxt, {freq+1, {key}});
            map[key] = newIt;
        }
        // Otherwise just place entry into an existing bucket
        else{
            auto& [_, newSet] = *it_nxt;
            newSet.insert(key);
            map[key] = it_nxt;

        }

        // Remove old entry from set and if it's now empty erase from linked list
        set.erase(key);
        if(set.empty()){
            linkedList.erase(listIt);
        }
    }
    
    void dec(string key) {
        auto it = map.find(key);
        
        if(it == map.end())
            return;

        auto listIt = it->second;
        auto& [freq, set] = *listIt;
        set.erase(key);
        
        if(freq == 1){
            map.erase(key);
            if(set.empty())
                linkedList.erase(listIt);
            return;
        }

        // No neigh to the left, can't do std::prev since UB
        if(listIt == linkedList.begin()){
            auto newIt = linkedList.insert(listIt, {freq-1, {key}});
            map[key] = newIt;
            if(set.empty()){
                linkedList.erase(listIt);
            }
            return;
        }
        
        auto it_prev = std::prev(listIt);
        if(it_prev->first != freq - 1){
            auto newIt = linkedList.insert(listIt, {freq-1, {key}});
            map[key] = newIt;
        }
        else{
            it_prev->second.insert(key);
            map[key] = it_prev;
        }
        
        if(set.empty()){
            linkedList.erase(listIt);
        }
    }
    
    string getMaxKey(){
        return linkedList.empty() ? "" : *linkedList.back().second.cbegin(); 
    }
    
    string getMinKey() {
        return linkedList.empty() ? "" : *linkedList.front().second.cbegin();
    }

private:
    // {freq, set of strings with that freq}
    list<pair<int,unordered_set<string>>> linkedList;
    unordered_map<string, list<pair<int,unordered_set<string>>>::iterator> map;
};