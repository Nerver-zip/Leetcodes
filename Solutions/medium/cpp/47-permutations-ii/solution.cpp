struct hashFunction 
  {
     size_t operator()(const vector<int> &myVector) const 
     {
         std::hash<int> hasher;
         size_t answer = 0;
         for (int i : myVector) 
        {
            answer ^= hasher(i) + 0x9e3779b9 + 
                              (answer << 6) + (answer >> 2);
       }
       return answer;
   }
};

class Solution {
private:
    std::unordered_set<vector<int>,hashFunction> seen; 

    void permutate(int index, vector<int>& nums, vector<vector<int>>& ans){
        if (index == nums.size())
        {
            if (seen.find(nums) == seen.end())
            {
                ans.push_back(nums); // Base case: add current permutation to the answer
            }
            seen.insert(nums);
        }
        for (int i = index; i < nums.size(); i++)
        {
            std::swap(nums[index],nums[i]); // Place nums[i] at current index
            permutate(index+1,nums,ans);    // Recurse for next index
            std::swap(nums[index],nums[i]); // Backtrack: restore original state
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutate(0,nums,ans);
        return ans;
    }
};