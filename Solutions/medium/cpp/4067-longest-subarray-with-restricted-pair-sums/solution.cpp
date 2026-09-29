// Rodamos uma sliding window
// ao incluir alguém, se a janela anterior era válida
// a unica maneira de ela ficar inválida é se o 
// novo elemento inviabilizar ela, 
// ou seja, reduzimos as comparações apenas as que envolvem
// o novo elemento
//
// Novo elemento = x
//
// 2 casos:
//
// a + b = x (two sum)
// x + a = b

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        const int n = nums.size();
        
        array<int, 501> freq{};
        
        int ans = min((int)nums.size(), 2);

        auto isInvalid = [&](int l, int r, int x){
            
            // caso 1:
            for(int i = l; i <= r; ++i){
                
                //não incluir i
                --freq[nums[i]];

                int diff_case1 = x - nums[i];
                int diff_case2 = x + nums[i];

                if(diff_case1 >= 0 && diff_case1 <= 500 && freq[diff_case1] || diff_case2 >= 0 && diff_case2 <= 500 && freq[diff_case2]){
                    ++freq[nums[i]];
                    return true;
                }
                
                ++freq[nums[i]];
            }

            return false;
        };

        for(int left = 0, right = 1; right < n; ++right){
            ++freq[nums[right-1]];
            
            while(right - left + 1 > 2 && isInvalid(left, right-1, nums[right])){
                --freq[nums[left]];
                ++left;
            }
            
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};