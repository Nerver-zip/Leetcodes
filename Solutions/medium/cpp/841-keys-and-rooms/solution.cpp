class Solution {
using Graph = vector<vector<int>>;

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        Graph g = buildGraph(rooms);
        vector<bool> visited(rooms.size());

        queue<int> q;
        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int u  = q.front();
            q.pop();

            for(int v : g[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
            
        for(bool b : visited)
            if(!b)
                return false;

        return true;
    }
private:

    Graph buildGraph(const vector<vector<int>>& rooms){
        Graph g(rooms.size());

        for(int r = 0; r < rooms.size(); ++r)
            for(int k : rooms[r])
                g[r].push_back(k);
        
        return g;
    }
};