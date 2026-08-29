class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int N = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < N - k + 1; ++i) {
            set<pair<int,int>, greater<>> set; 
            array<int, 51> freq{};
            
            for (int j = i; j < k + i; ++j)
                ++freq[nums[j]];

            for (int n = 1; n <= 50; ++n)
                if(freq[n] != 0)
                    set.insert({freq[n],n});

            int l = 0, sum = 0;

            for(auto it = set.begin(); it != set.end() && l < x; ++it, ++l)
                sum += it->first * it->second;
            ans.push_back(sum);
        }
        
        return ans;
    }
};