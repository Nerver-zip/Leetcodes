class Allocator {
private:
    vector<std::pair<int,int>> memory;
public:
    Allocator(int n){
        int freeSlots = n;
        for (int i = 0; i < n ; i++)
        {
            memory.push_back({0,freeSlots--});
        }
    }
    
    int allocate(int size, int mID) {
        
        int leftMost = -1;
        int indexCount = 0;

        for (const auto& block : memory)
        {
            if (block.second >= size)
            {
                leftMost = indexCount;
                break;
            }
            indexCount++;
        }
        
        if (leftMost == -1)
            return -1;
        
            
        for (int i = 0; i < size; i++)
            memory[indexCount++] = {mID,0};
        
        return leftMost;
    }
    
    int freeMemory(int mID) {
        int units = 0;
        int contiguousCount = 0;
        for (int i = memory.size()-1; i >= 0; i--)
        {
            if (memory[i].first == mID)
            {
                memory[i] = {0,++contiguousCount};
                units++;
            }
            else if (memory[i].first == 0)
            {
                memory[i] = {0,++contiguousCount};
            }
            else
                contiguousCount = 0;
        }
        return units;
    }
};
/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */