class Solution {
public:
    int minOperations(string s, int k) {
        const int n = s.size();

        int z_count = 0;

        for(char c : s)
            if(c == '0')
                ++z_count;

        if(z_count == 0)
            return 0;

        // Minimum operations to reach state with i zeros
        vector<int> dist(n + 1, numeric_limits<int>::infinity());
        
        // Unvisited states with separated by parity (z % 2) == parity
        vector<set<int>> unvisited(2);

        for(int z = 0; z <= n; ++z)
            unvisited[z % 2].insert(z);
    
        queue<int> q;
        q.push(z_count);
        dist[z_count] = 0;
        unvisited[z_count % 2].erase(z_count);

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int ones = n - z;
            // x -> #n of zeros flipped
            // Constraints:
            // 0 <= x <= k
            // x <= z
            // k-x <= ones
            
            int xMin = max(0, k-ones);
            int xMax = min(k,z);
            if(xMin > xMax)
                continue;

            int l = z + k - 2 * xMax;
            int r = z + k - 2 * xMin;

            auto& set = unvisited[l % 2];

            // Enumerating only unvisited states in [l, r] of that parity
            for(auto it = set.lower_bound(l); it != set.end() && *it <= r;){
                int z2 = *it;
                dist[z2] = dist[z] + 1;
                q.push(z2);
                it = set.erase(it);
            }
        }

        return dist[0] == numeric_limits<int>::infinity() ? -1 : dist[0];
    }
};