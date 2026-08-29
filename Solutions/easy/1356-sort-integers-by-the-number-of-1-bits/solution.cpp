class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const uint& a, const uint& b){
            int bits_a = popcount(a), bits_b = popcount(b);
            
            if(bits_a != bits_b)
                return bits_a < bits_b;
            
            return a < b;
        });

        return arr;
    }
};