class NumberContainers {
private:
    std::unordered_map<int,int> numContainer;
    std::unordered_map<int,std::set<int>> indexContainer;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if (numContainer.find(index) != numContainer.end()) //will be overwriting that index
        {
            int key = numContainer[index];
            indexContainer[key].erase(index);
        }
        numContainer[index] = number;
        indexContainer[number].insert(index);
    }
    
    int find(int number) {
        auto it = indexContainer[number].begin();
    
        if (it == indexContainer[number].end())
        {
            return -1;
        }
        
        return *it;
    }
};