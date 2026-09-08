class Solution {
public:
    int largestInteger(int n, int s) {
        vector<int> digits(n, 9);

        for(int i = n-1; i >= 0; --i){
            int res = accumulate(digits.begin(), digits.end(),0);
            if(res == s){
                return getNumber(digits); 
            }
            while(digits[i]){
                --digits[i];
                res = accumulate(digits.begin(), digits.end(),0);
                if(res == s)
                    return getNumber(digits);
            }

        }
        return -1;
    }

private:
    int getNumber(const vector<int>& v){
        int ans = 0;
        int e = v.size()-1;
        
        for(int n : v){
            int mul = pow(10, e);
            --e;
            ans += n * mul;
        }

        return ans;
    }
};