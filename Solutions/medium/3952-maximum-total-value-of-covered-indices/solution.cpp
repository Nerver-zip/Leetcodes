class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans = 0;
        int i = 0;

        // Skippa bloco continuo de 1
        while(i < nums.size() && s[i] == '1'){
            ans += nums[i];
            ++i;
        }
        
        // E.g -> s = "011" nums = [3, 10, 1]
        // Contabiliza a soma contando o zero a esquerda e retira o mínimo
        for(;i<nums.size(); ++i){
            if(s[i]=='1'){
            long long count_zero = 0;
            int minimum = INT_MAX;
                count_zero += nums[i-1];
                minimum = nums[i-1];
                while(i < nums.size() && s[i] == '1'){
                    count_zero += nums[i];
                    minimum = min(minimum, nums[i]);
                    i++;
                }
                ans += count_zero - minimum;
            }
        }

        return ans;
    }
};