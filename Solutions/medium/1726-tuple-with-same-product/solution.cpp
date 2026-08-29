class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        std::unordered_map<int,int> productMap;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                    productMap[nums[i] * nums[j]]++;
            }
        }
        
        for (const auto& [product, count] : productMap)
        {
            if (count >= 4)
                ans += count * (count - 2); //Eight times the binomial coefficient of k choose two
                                            //where k = count/2 so it simplifies to that expression                                            
        }
        return ans;
    }
};