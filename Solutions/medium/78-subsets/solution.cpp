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
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(nums, 0, curr);
        
        vector<vector<int>> ans;

        for (const auto& set : sub) {
            ans.push_back(set);
        }            
        return ans;
    }
private:
    unordered_set<vector<int>, hashFunction> sub;

    void backtrack(const vector<int>& nums, int idx, vector<int>& curr){
        sub.insert(curr);

        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backtrack(nums, i+1, curr);
            curr.pop_back();
        } 
    }
};