class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq1, freq2;
        map<int, int> totalFreq;

        int n = basket1.size();
        int minimum = INT32_MAX;

        for (int i = 0; i < n; ++i) {
            freq1[basket1[i]]++;
            freq2[basket2[i]]++;
            totalFreq[basket1[i]]++;
            totalFreq[basket2[i]]++;
            minimum = min({minimum, basket1[i], basket2[i]});
        }

        for (auto [num, freq] : totalFreq) {
            if (freq % 2 != 0) return -1;
        }

        vector<int> toSwap;
        
        //Count differs
        for (auto [num, total] : totalFreq) {
            int f1 = freq1[num];
            int f2 = freq2[num];
            int diff = f1 - total / 2;

            //Exceeding in b1
            if (diff > 0) {
                for (int i = 0; i < diff; ++i) {
                    toSwap.push_back(num);
                }
            }
            //Exceeding in b2
            else if (diff < 0) {
                for (int i = 0; i < -diff; ++i) {
                    toSwap.push_back(num);
                }
            }
        }

        sort(toSwap.begin(), toSwap.end());

        long long cost = 0;
        int m = toSwap.size();
        for (int i = 0; i < m / 2; ++i) {
            //check whether it's better to use minimum as bridge or a normal swap
            cost += min(toSwap[i], 2 * minimum);
        }
        return cost;
    }
};