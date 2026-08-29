class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        const int size = fruits.size();
        vector<bool> placed(size);
        int ans = size;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if(!placed[j] && fruits[i] <= baskets[j]){
                    placed[j] = true;
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};