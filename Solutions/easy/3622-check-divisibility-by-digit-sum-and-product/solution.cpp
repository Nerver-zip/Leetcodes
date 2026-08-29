class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1, x = n;
        
        while(x){
            product *= x % 10;
            sum += x % 10;
            x /= 10;
        }
        
        return n % (product + sum) == 0;
    }
};