class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorSum = 0;
        for (const auto& num : derived)
        {
            xorSum ^= num;
        }      
        return xorSum == 0;
    }
};