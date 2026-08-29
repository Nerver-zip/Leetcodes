class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<long long> ans(n);

        for (auto& [val, v] : pos) {
            int k = v.size();

            long long total = 0;
            for (int x : v) 
                total += x;

            long long leftSum = 0;

            for (int t = 0; t < k; t++) {
                long long i = v[t];
                
                // parte t * i contribui positivamente e left sum é a parte da subtração dos índices que passaram
                
                // left = soma das distâncias de i até os elementos antes dele
                long long left = t * i - leftSum;
                
                // (total - left - i) soma dos valores da direita
                // (k - t - 1) * i = soma dos valores i da direita

                // right = soma das distâncias de i até os elementos depois dele
                long long right = (total - leftSum - i) - (k - t - 1) * i;

                ans[i] = left + right;

                leftSum += i;
            }
        }

        return ans;

    }
};