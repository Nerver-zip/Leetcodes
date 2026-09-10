class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total_apples = accumulate(apple.begin(), apple.end(), 0);

        sort(capacity.begin(), capacity.end(), [](const auto& a, const auto& b){return a > b;});
        
        int i = 0;
        while (i < capacity.size() && total_apples > 0) {
            total_apples -= capacity[i]; 
            ++i;
        }

        return i;
    }
};