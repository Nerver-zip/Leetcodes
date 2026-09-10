class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_set<int> seen;
        
        int n = 1;
        int count = 1;
        while(true){

            n %= k;

            if(n == 0)
                return count;
            
            if(!seen.count(n))
                seen.insert(n);
            else
                return -1; 

            n *= 10;
            n += 1;

            ++count;    
        }

        return -1;
    }
};