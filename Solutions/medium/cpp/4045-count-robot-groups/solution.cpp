class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        const int n = position.size();
        
        int ans = n;
        
        int groupSpeed = speed[n-1];

        for(int i = n-2; i >= 0; --i){
            if(position[i+1] - position[i] <= distance || speed[i] > groupSpeed){
                --ans;
            }
            else{
                groupSpeed = speed[i];
            }
        }

        return ans;
    }
};