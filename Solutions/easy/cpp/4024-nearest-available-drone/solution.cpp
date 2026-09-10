class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int nearest = numeric_limits<int>::max();

        int d = 0;
        int ans = d;
        for(const auto& drone : drones){
            int x = drone[0], y = drone[1], range = drone[2];
            int xf = target[0], yf = target[1];

            int dist = abs(x - xf) + abs(y - yf);
            
            if(range >= dist){
                if(nearest > dist){
                    nearest = dist;
                    ans = d;
                }
            }
            ++d;
        }

        return nearest == numeric_limits<int>::max() ? -1 : ans;
    }
};
