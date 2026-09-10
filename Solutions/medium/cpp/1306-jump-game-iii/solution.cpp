class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        queue<int> q;
        vector<bool> visited(n);

        q.push(start);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(arr[u] == 0)
                return true;
            
            int vx = u + arr[u];
            int vy = u - arr[u];

            if(!isOutOfBounds(vx, n) && !visited[vx]){
                visited[vx] = true;
                q.push(vx);
            }
            if(!isOutOfBounds(vy, n) && !visited[vy]){
                visited[vy] = true;
                q.push(vy);
            }
        }
        
        return false;
    }
private:
    bool isOutOfBounds(int idx, int n) const {
        return idx < 0 || idx >= n;
    }
};