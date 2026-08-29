class Solution {
public:
    long long flowerGame(long long n, long long m) {
        //Calculate odd and even numbers from [1, n] and [1,m]
        //Return: odd(n) * even(m) + even(n) * odd(m)
        return ((n + 1)/2) * (m/2) + ((n/2) * ((m+1)/2));  
    }
};