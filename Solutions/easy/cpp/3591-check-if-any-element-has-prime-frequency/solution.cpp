class Solution {
private:
    bool isPrime(int n){
        int divisible = 0;
        if(n == 0 || n == 1)
            return false;
        for (int i = 2; i < n; ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int x : nums)
            freqMap[x]++;

        for (const auto& [_, freq] : freqMap)
            if(isPrime(freq))
                return true;
        return false;
    }
};