class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> dpRight(height.size()); //max height seen from a point looking forward
        int ans = 0;

        int max = height[height.size()-1];
        for (int i = height.size()-1; i >= 0; i--)
        {
            max = std::max(max, height[i]);
            dpRight[i] = max;
        }

        int maxLeft = height[0];
        for (int i = 1; i < height.size()-1; i++) //Skip first and last position
        {
            maxLeft = std::max(maxLeft, height[i]);
            ans += std::min(maxLeft, dpRight[i]) - height[i];
        }

        return ans;
    }
};