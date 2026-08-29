class Solution {
private:
    //Decompose a number into a vector of frequencies 
    vector<int> decompose(int n){
        vector<int> freq(10, 0); //0-9
        
        while (n) {
            ++freq[n % 10];
            n /= 10;
        }

        return freq;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> decomposedPowers;
        int p = 0;
        while (p < 31) {
            decomposedPowers.push_back(decompose(pow(2, p)));
            ++p;
        }
        
        vector<int> decomposedNumber = decompose(n);
        
        for (const auto& decomposition : decomposedPowers) {
            bool found = true;
            for (int i = 0; i < 10; ++i) {
                if(decomposition[i] != decomposedNumber[i]){
                    found = false;
                    break;
                }
            }
            if(found)
                return true;
        }
        
        return false;
    }
};