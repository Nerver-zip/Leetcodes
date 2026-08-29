class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<long long> prefix;
        //fix arbitrary element
        prefix.push_back(0);

        int max = prefix[0];
        int min = prefix[0];

        //build from there
        //store max and min
        for (const auto& diff : differences){
            prefix.push_back(prefix.back()-diff);
            if (prefix.back() > max)
                max = prefix.back();
            else if (prefix.back() < min)
                min = prefix.back();
        }
        
        //arbitrary element doesnt affect this
        long long range = max - min;

        int ans = (upper - lower + 1) - range;

        return ans >= 0 ? ans : 0;
    }
};