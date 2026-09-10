class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> nums2Map;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int n : nums2)
            ++nums2Map[n];
        this->nums1 = nums1; 
        this->nums2 = nums2;  
    }
    
    void add(int index, int val) {
        --nums2Map[nums2[index]];        
        nums2[index] += val;
        ++nums2Map[nums2[index]];
    }
    
    int count(int tot) {
        int count = 0;
        for (int i = 0; i < nums1.size(); ++i)
        {
            int x = tot - nums1[i];
            if (nums2Map.find(x) != nums2Map.end())
                count += nums2Map.at(x);
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */