class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        const int size = fruits.size();
        unordered_map<int, int> freq;
        int left = 0, curr = 0, ans = 1;

        for(int right = 0; right < size; ++right){
            ++freq[fruits[right]];
            while (freq.size() > 2) {
                --freq[fruits[left]]; 
                if(freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                ++left;
            }
            curr = right - left + 1;
            ans = max(ans, curr);
        }
        return ans;
    }
};