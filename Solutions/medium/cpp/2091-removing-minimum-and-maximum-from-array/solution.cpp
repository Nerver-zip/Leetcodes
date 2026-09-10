class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        auto mx = ranges::max_element(nums);        
        auto mn = ranges::min_element(nums);

        int pos_max = mx - nums.begin();
        int pos_min = mn - nums.begin();

        // Só existem 3 caminhos.
        // 1. Só da direta
        // 2. Só da esquerda
        // 3. Direita + Esquerda
        
        int onlyFromLeft = pos_max > pos_min ? pos_max + 1 : pos_min + 1;
        int onlyFromRight = pos_max < pos_min ? n - pos_max : n - pos_min;

        int fromLeft = pos_max < pos_min ? pos_max + 1 : pos_min + 1; 
        int fromRight = pos_max > pos_min ? n - pos_max : n - pos_min;

        return min({onlyFromRight, onlyFromLeft, fromLeft + fromRight});
    }
};