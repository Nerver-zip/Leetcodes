class Solution {
private:
    int hasZero(int n){
        while (n) {
            if(n % 10 == 0)
                return true;
            n /= 10;
        }
        return false;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        
        vector<int> ans = {n/2, n/2};
        
        if(ans[0] + ans[1] != n)
            ++ans[1];

        while (hasZero(ans[0]) || hasZero(ans[1])) {
            --ans[0]; ++ans[1];
        }
        
        return ans;
    }
};