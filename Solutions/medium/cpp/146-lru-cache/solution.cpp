class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        
        if(it == map.end())
            return -1;
        
        auto list_it = it->second;
        // pega o elemento apontado pot it e joga pra antes do apontado por list.begin()
        linkedList.splice(linkedList.begin(), linkedList, list_it);
        return list_it->second;
    }
    
    void put(int key, int value) {
        auto map_it = map.find(key);

        if(map_it == map.end()){
            if(linkedList.size() == capacity){
                auto tail = linkedList.back();
                map.erase(tail.first);
                linkedList.pop_back();
            }

            linkedList.push_front({key, value});
            map.insert({key, linkedList.begin()});
            return;
        }
        
        auto list_it = map_it->second;
        list_it->second = value;
        linkedList.splice(linkedList.begin(), linkedList, list_it);
    }

private:
    // {key, val}
    list<pair<int,int>> linkedList;
    unordered_map<int, list<pair<int,int>>::iterator> map;  
    int capacity;
};