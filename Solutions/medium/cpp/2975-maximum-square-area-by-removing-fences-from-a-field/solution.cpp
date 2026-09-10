constexpr int MOD = 1000000007; 
using ll = long long;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        hFences.push_back(m);
        vFences.push_back(n);
        
        unordered_set<int> vFencesDiff;
        
        vector<int> hFencesDiff;
         
        int prev = 1; 
        for (int i = 0; i < hFences.size(); ++i) {
            for (int j = i; j < hFences.size(); ++j) {
                hFencesDiff.push_back(hFences[j] - prev);    
            }
            prev = hFences[i];
        }
      
        prev = 1; 
        for (int i = 0; i < vFences.size(); ++i) {
            for (int j = i; j < vFences.size(); ++j) {
                vFencesDiff.insert(vFences[j] - prev);    
            }
            prev = vFences[i];
        }

        ll maxDiff = -1;
        
        for (int diff : hFencesDiff) {
            if(diff > maxDiff && vFencesDiff.count(diff))
                maxDiff = diff;
        }

        return maxDiff == -1 ? -1 : (maxDiff * maxDiff) % MOD; 
    }
};