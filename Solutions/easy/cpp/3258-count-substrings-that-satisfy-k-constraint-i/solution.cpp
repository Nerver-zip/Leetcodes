using ll = long long;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        // Resposta será complemento. Buscaremos quantas substrings violam a constraint
        // n(n+1)/2 - violações = ans
        const int n = s.size();
        
        ll total = n * (n + 1) / 2;
        ll violations = 0;

        int zero_count = 0;
        int one_count = 0;
        for(int left = 0, right = 0; right < n; ++right){
            if(s[right] == '0'){
                ++zero_count;
            }
            else{
                ++one_count;
            }

            while(zero_count > k && one_count > k){
                violations += n - right;
                
                if(s[left] == '0'){
                    --zero_count;
                }
                else{
                    --one_count;
                }

                ++left;
            }    
        }

        return total - violations;
    }
};