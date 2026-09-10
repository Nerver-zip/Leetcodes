class Solution {
public:
    bool isDigitorialPermutation(int n) {
        const int N = n;
        int factSum = 0;
        vector<int> nums;

        vector<int> freqFact(10), freqOg(10);

        while(n){
            int digit = n % 10;
            ++freqOg[digit];
            nums.push_back(digit);
            factSum += factorial(digit);
            n /= 10;
        }
        
        while(factSum){
            ++freqFact[factSum % 10];
            factSum /= 10;
        }
        
        return freqOg == freqFact;
    }
private:
    int factorial(int n){
        if(n == 0 || n == 1)
            return 1;
        return n * factorial(n-1);
    }
};