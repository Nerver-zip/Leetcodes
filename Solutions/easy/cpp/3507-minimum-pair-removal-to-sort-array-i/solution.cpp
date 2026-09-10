class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        auto isSorted = [&](){
            for (int i = 0; i < nums.size()-1; ++i) {
                if(nums[i+1] < nums[i])
                    return false;
            }
            return true;
        };
        
        int operations = 0;
        while (!isSorted()) {
            array<int, 3> arr = {INT_MAX, INT_MAX, INT_MAX};
            for (int i = 0; i < n-1; ++i) {
                arr = min(arr, {nums[i] + nums[i+1], i, i+1});
            }

            vector<int> v;
            v.reserve(n-1);
            auto [sum, idx1, idx2] = arr;

            for (int i = 0; i < n; ++i) {
                if(i == idx1)
                    v.push_back(sum);
                else if(i != idx2)
                    v.push_back(nums[i]);
            }
            --n;
            ++operations;
            
            nums = std::move(v);
        }

        return operations;
    }
};