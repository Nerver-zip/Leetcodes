class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> state(101);

        for(int n : bulbs){
            state[n] = !state[n];
        }
        
        vector<int> ans;
        for(int i = 1; i <= 100; ++i){
            if(state[i])
                ans.push_back(i);
        }

        return ans;
    }
};