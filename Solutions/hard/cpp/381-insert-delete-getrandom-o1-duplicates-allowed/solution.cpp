class RandomizedCollection {
public:
    RandomizedCollection() {
        std::srand(std::time(0)); 
    }
    
    bool insert(int val) {
        multiset.push_back(val);

        auto it = pos.find(val);
        pos[val].insert(multiset.size()-1);

        if(it == pos.end()){ 
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        auto it = pos.find(val);

        if(it == pos.end())
            return false;

        auto& set = it->second;
        int i = *set.cbegin();
        
        // just delete, no map and nums realocation
        if(val == multiset.back()){
            set.erase(multiset.size()-1);
            multiset.pop_back();
            
            if(set.empty()){
                pos.erase(it);
            }
            
            return true;
        }
        
        // otherwise we have to do some element reallocation
        // i.e. assign map[nums.back()] to idx being removed and pop back 
        
        auto& set2 = pos[multiset.back()];
       
        // delete size-1 pos
        set2.erase(multiset.size()-1);
        set2.insert(i);

        // erase from val list and multiset
        set.erase(i);

        // multiset replace 
        multiset[i] = multiset.back();
        multiset.pop_back();
        
        if(set.empty()){
            pos.erase(it);
        }

        return true;
    }
    
    int getRandom() {
        return multiset[rand() % multiset.size()];
    }
private:
    // val -> list of indices of its appearances in multiset
    unordered_map<int, set<int>> pos;
    vector<int> multiset;
};