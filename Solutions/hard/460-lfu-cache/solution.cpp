class LFUCache {
public:
    LFUCache(int capacity) {
        minFreq = 0;
        MAX_CAPACITY = capacity;
        size = 0;
    }
    
    int get(int key) {
        auto it_map = map.find(key);
        
        if(it_map == map.end())
            return -1;
        
        // find node
        auto [f, it_list] = it_map->second;
        
        // get its value
        auto [_, v] = *it_list;
        
        // remove node from linked list of frequency f
        auto& list = freq[f];
        list.erase(it_list);
            
        // K now belongs to the linked list of frequency f+1
        // placed in the front to follow LRU policy 
        freq[f+1].push_front({key, v});

        // update map
        map.erase(key);
        map[key] = {f+1, freq[f+1].begin()};
        
        if(list.empty() && minFreq == f)
            ++minFreq;

        return v;
    }
    
    void put(int key, int value) {
        auto map_it = map.find(key);
        
        // new key
        if(map_it == map.end()){
            
            // MAX_CAPACITY reached
            // we need to erase the minFreq key
            // if tie, follow LRU policy (erase linked list back)
            if(size == MAX_CAPACITY){
                // Deleting least frequently used key
                auto& minFreqList = freq[minFreq];
                auto [erasedKey, _] = *minFreqList.rbegin();
                minFreqList.pop_back();
                map.erase(erasedKey);
                --size;
            }
            
            // Inserting key
            freq[1].push_front({key, value});
            map[key] = {1, freq[1].begin()};
            minFreq = 1;
            ++size;
            return;
        }

        // updating key 
        auto [f, list_it] = map_it->second;
        
        auto& listToErase = freq[f];

        // remove K from list of frequency f
        listToErase.erase(list_it);

        // K now belongs to the linked list of frequency f+1
        // placed in the front to follow LRU policy 
        freq[f+1].push_front({key, value});
        
        // update map
        map.erase(key);
        map[key] = {f+1, freq[f+1].begin()};

        if(listToErase.empty() && minFreq == f)
            ++minFreq;
    }


private:
    int MAX_CAPACITY;
    int size;
    int minFreq;
    
    // {K, V} 
    // {freq -> list {K,V}}
    unordered_map<int, list<pair<int,int>>> freq;
    
    // {K, {f, list iterator}}
    unordered_map<int, pair<int,list<pair<int,int>>::iterator>> map;
    
};