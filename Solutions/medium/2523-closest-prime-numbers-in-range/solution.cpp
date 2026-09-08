#define INFINTE 10000000
class Solution {
private:
    vector<int> SieveOfEratosthenes(int n, int left)
    {
        vector<bool> prime(n + 1, true);
        vector<int> primeList;

      for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }   
        for (int p = 2; p <= n; p++){
            if (prime[p] && p >= left){
                primeList.push_back(p);
            }
        }
        return primeList;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primeList = SieveOfEratosthenes(right, left);
        int minDist = INFINTE;
        vector<int> closest = {-1,-1};

        if (primeList.size() > 1){
            for (int i = 0; i < primeList.size()-1; i++)
            {
                int currDist = primeList[i+1] - primeList[i];
                if (currDist < minDist)
                {
                    minDist = currDist;
                    closest[0] = primeList[i];
                    closest[1] = primeList[i+1];
                }
            }
        }
        return closest;
    }
};