class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;

        for(int x = 1; x < n * 2; ++x){
            if(x & 1)
                oddSum += x;
            else
                evenSum += x;
        }

        return gcd(oddSum, evenSum);
    } 
};