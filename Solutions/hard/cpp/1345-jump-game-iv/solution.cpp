class Solution {
public:
    int minJumps(vector<int>& arr) {
        n = arr.size();
        unordered_map<int, vector<int>> map;

        for(int i = 0; i < arr.size(); ++i)
            map[arr[i]].push_back(i);
        
        vector<int> dist(n, numeric_limits<int>::max());
        dist[0] = 0;

        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            auto [idx, steps] = q.front();
            q.pop();
            
            if(steps > dist[idx])
                continue;
            
            if(idx == n-1)
                return steps;
            
            int nstep = steps + 1; 
            if(!isOutOfBounds(idx + 1, n) && dist[idx + 1] > nstep){
                dist[idx + 1] = nstep;
                q.push({idx + 1, nstep});
            }
            if(!isOutOfBounds(idx - 1, n) && dist[idx - 1] > nstep){
                dist[idx - 1] = nstep;
                q.push({idx - 1, nstep});
            }

            auto& list = map[arr[idx]];
            for(int i : list){
                if(i != idx && dist[i] > nstep){
                    dist[i] = nstep;
                    q.push({i, nstep});
                }
            }
            
            map[arr[idx]].clear();
        }
        
        return n-1;
    }
private:
    int n;
    bool isOutOfBounds(int i, int n) const {
        return i < 0 || i >= n;
    }
};