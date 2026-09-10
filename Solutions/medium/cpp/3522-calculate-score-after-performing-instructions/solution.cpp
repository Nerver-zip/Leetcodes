class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans = 0;
        vector<bool> executed(instructions.size());
        int i = 0;
        while (i >= 0 && i < values.size() && !executed[i])
        {
            if (instructions[i][0] == 'j'){
                executed[i] = true;
                i += values[i];
            }
            else
            {
                executed[i] = true;
                ans += values[i];
                i++;
            }
        }
        return ans;
    }
};