class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges){
        vector<int> degree(n+1);

        for(const auto& edge : edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
                
        int oddDegrees = 0;
        vector<int> oddVertexes;
        for(int i = 1; i <= n; ++i){
            if(degree[i] & 1){
                oddVertexes.push_back(i);
            } 
        }
        // Case1: No odd degree
        if(oddVertexes.size() == 0)
            return true;
        

        vector<vector<int>> graph = buildGraph(n, edges);
        auto canConnect = [&](int a, int b){
            for(int v : graph[a])
                if(v == b)
                    return false;
            return true;
        };    
    

        // Case 2: Exactly 2 degrees are odd
        // Notice that we cant blindly connect them since they might already be connected
        // In that case 
        if(oddVertexes.size() == 2){
        // Either we connect these two, or we connect them to a single even degree vertex
        // So that vertex can stay even
            bool canAdd = true;
            for(int v : graph[oddVertexes[0]]){
                if(v == oddVertexes.back()){
                    canAdd = false;
                    break;
                }
            }

            if(canAdd)
                return true;
            
            for(int u = 1; u <= n; ++u){
                if(u == oddVertexes.front() || u == oddVertexes.back())
                    continue;
            
                if(canConnect(u, oddVertexes.front()) && canConnect(u, oddVertexes.back()))
                    return true;
            }
            return false;
        }
        // Case 3: Exactly 4 Degrees are odd
        // Test (a,b) (c,d)
        //      (a,c) (b,d)
        //      (a,d) (b,c)
        else if(oddVertexes.size() == 4){
            auto& o = oddVertexes;


            // (a,b) (c,d)
            if(canConnect(o[0], o[1]) && canConnect(o[2], o[3]))
                return true;

            // (a,c) (b,d)
            if(canConnect(o[0], o[2]) && canConnect(o[1], o[3]))
                return true;

            // (a,d) (b,c)
            if(canConnect(o[0], o[3]) && canConnect(o[1], o[2]))
                return true;

            return false;
        }

        return false;
    }
private:
    vector<vector<int>> buildGraph(int n, const vector<vector<int>>& edges){
        vector<vector<int>> graph(n+1);

        for(const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }
};