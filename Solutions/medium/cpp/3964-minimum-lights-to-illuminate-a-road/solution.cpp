class Solution {
public:
    int minLights(vector<int>& lights) {
        const int n = lights.size();
        vector<int> line(n+1, 0);

        for(int i = 0; i < n; ++i){
            if(lights[i] > 0){
                int left = max(0, i - lights[i]);
                int right = min(n-1, i + lights[i]);
                ++line[left];
                --line[right + 1];
            }
        }
        
        for(int i = 1; i < line.size(); ++i){
            line[i] += line[i-1];
        }
        line.pop_back();
        
        int ans = 0;
        // greedy
        for(int i = 0; i < n; ++i){
            if(!line[i]){
                if(i < n-1){
                    line[i+1] = 1;
                }
                if(i < n-2){
                    line[i+2] = 1;
                }
                if(i > 0){
                    line[i] = 1;
                }
                ++ans;
            }
        }

        return ans;
    }
};