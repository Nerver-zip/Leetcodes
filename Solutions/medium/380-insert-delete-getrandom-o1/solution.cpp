class RandomizedSet {

public:
    RandomizedSet() {
        std::srand(std::time(0)); 
    }
    
    bool insert(int val) {
        auto it = pos.find(val);
        
        if(it != pos.end())
            return false;
        
        nums.push_back(val);
        pos.insert({val, nums.size()-1});

        return true;
    }
    
    bool remove(int val) {
        auto it = pos.find(val);

        if(it == pos.end())
            return false;
        
        int i = it->second;
        
        // update map to match new index
        pos[nums.back()] = i;
        nums[i] = nums.back();
        
        pos.erase(val);
        nums.pop_back();
        
        return true;
    }
    
    int getRandom() { 
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> pos;
};