class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int n = left; n <= right; ++n){
            auto digits = getDigits(n);
            for(int d : digits){
                if(d == 0 || n % d != 0)
                    goto end_loop;
            }

            ans.push_back(n);
            
            end_loop:
        }

        return ans;
    }
private:
    vector<int> getDigits(int n){
        vector<int> digits;

        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }

        return digits;
    }
};