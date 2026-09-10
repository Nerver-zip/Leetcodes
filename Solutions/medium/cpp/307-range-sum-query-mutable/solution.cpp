class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit = {0};
        this->nums = nums;
        bit.insert(bit.end(), nums.begin(), nums.end());

        for(int i = 1; i <= n; ++i){
            int j = i + (i & -i);

            if(j <= n){
                bit[j] += bit[i];
            }
        }
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;

        ++index;
        while(index <= n){
            bit[index] += delta;
            index += index & -index; 
        }
    }
    
    int prefixSum(int index){
        int sum = 0;
        
        ++index;
        while(index > 0){
            sum += bit[index];
            index -= index & -index;
        }

        return sum;
    }

    // query
    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }

private:
    vector<int> bit;
    vector<int> nums;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */