class Solution {
private:
    bool findPermutation(vector<int>& nums, std::unordered_set<int>& used, int index, int N){
        if (index == nums.size()) {
            return true;
        }
        for (int curr = N; curr > 0; curr--) { 
            if (used.find(curr) != used.end() || (curr > 1) && (index+curr >= nums.size() || nums[index+curr]))
            {
                continue;
            }
            
            used.insert(curr);
            nums[index] = curr;
            if(curr > 1)
            {
                nums[curr+index] = curr;
            }

            int nextIndex = index + 1;
            while (nextIndex < nums.size() && nums[nextIndex])
            {
                nextIndex++;
            }
            
            if (findPermutation(nums,used,nextIndex,N))
            {
                return true;
            }
            //backtrack
            used.erase(curr);
            nums[index] = 0;
            if(curr > 1)
            {
                nums[curr+index] = 0;
            }

        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> nums(n*2-1,0);
        std::unordered_set<int> used;

        findPermutation(nums,used,0,n);

        return nums;
    }
};