#define MAX 501
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freqMap(MAX, 0);
    
        for (int n : arr)
            freqMap[n]++;
        
        for (int i = freqMap.size()-1; i >= 1; --i)
            if(freqMap[i] == i)
                return i;
        
        return -1;
    }
};   