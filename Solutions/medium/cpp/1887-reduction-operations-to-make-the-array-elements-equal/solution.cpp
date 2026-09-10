class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        const int size = nums.size();
        sort(nums.begin(), nums.end());        
        
        int ans = 0;
        //Brute force (TLE)
        /*while (nums[0] != nums[size-1]) {
            auto it_largest = lower_bound(nums.begin(), nums.end(), nums[size-1]);
            auto it_nextLargest = it_largest - 1;
            
            *it_largest = *it_nextLargest;
            ++ans;
        }*/
        
        //If an element differs, we know we need to update
        //the entire array to the right
        for (int i = 1; i < size; i++)
            if (nums[i] != nums[i - 1])
                ans += (size - i);

        return ans;
    }
};