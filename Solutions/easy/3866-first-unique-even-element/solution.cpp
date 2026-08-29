class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int n : nums)
            ++freq[n];

        for(int n : nums){
            if(n % 2 == 0 && freq[n] == 1)
                return n;
        }

        return -1;
    }
};

