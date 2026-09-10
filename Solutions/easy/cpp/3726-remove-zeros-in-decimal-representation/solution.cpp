class Solution {
public:
    long long removeZeros(long long n) {
        return paddZeros(n);
    }
private:
    long long paddZeros(long long n){
        string num;
        while (n) {
            long long digit = n % 10;
            if(digit != 0)
                num += digit + '0';
            n /= 10;
        }
        reverse(num.begin(), num.end());
        return stoll(num);
    }
};