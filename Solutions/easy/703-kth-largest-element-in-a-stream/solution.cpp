class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for(int n : nums)
            stream.insert(n);

        this->k = k-1;
    }
    
    int add(int val) {
        stream.insert(val);
    
        auto it = std::next(stream.rbegin(), k);
        
        // if there arent k elements in stream return the smallest
        if(it == stream.rend())
            return *stream.cbegin();

        return *it;
    }


private:
    multiset<int> stream;
    int k;
};