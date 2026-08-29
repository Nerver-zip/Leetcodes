class Solution {
private:
    bool isPrime(long long n) {
        if (n <= 1) return false;          
        if (n == 2) return true;           
        if (n % 2 == 0) return false;
    
        long long limit = sqrt(n);         
        for (long long i = 3; i <= limit; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        set<long long> uniquePrime;

        for (int i = 0; i < s.size(); ++i)
        {
            int k = 0;
            for (int j = i; j < s.size(); ++j)
            {
                auto substring = s.substr(i, k + 1) + "\0";
                const auto csubstring = substring.c_str();
                long long n = atoll(csubstring);
                if (isPrime(n))
                    uniquePrime.insert(n);
                k++;
            }
        }
        long long sum = 0;
        int count = 0;
        
        auto it = uniquePrime.crbegin();

        for (int i = 0; i < uniquePrime.size() && i < 3; ++i)
        {
            long long n = *it;
            it.operator++();
            sum += n;
        }
        return sum;
    }
};