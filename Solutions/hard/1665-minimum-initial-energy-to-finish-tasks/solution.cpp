class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b){
            return a[1] - a[0] > b[1] - b[0];
            
        });

        auto solve = [&tasks](int energy)->bool{
            for(const auto& task : tasks){
                int actual = task[0], minimum = task[1];
        
                if(energy >= minimum)
                    energy -= actual;
                else
                    return false;
            }

            return true;
        };

        int left = 0, right = 1e4 * tasks.size();    
        int ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;

            if(solve(mid)){
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return ans;
    }
};