class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prevCount = 0, ans = 0;

        for (const auto& row : bank) {
            int currCount = 0;
            
            for (char n : row)
                if(n == '1')
                    ++currCount;

            ans += prevCount * currCount;
            prevCount = currCount != 0 ? currCount : prevCount;
        }
        
        return ans;
    }
};