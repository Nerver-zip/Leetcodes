class Solution {
private:
    int getMinSteps(int left, int right, int start){
        return min(abs(start-left) + right - left, abs(start-right) + right - left); //Minimum of going left then right and vice-versa
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0, curr = 0, ans = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            curr += fruits[right][1];
            while (left <= right && getMinSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                curr -= fruits[left][1];
                ++left;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};