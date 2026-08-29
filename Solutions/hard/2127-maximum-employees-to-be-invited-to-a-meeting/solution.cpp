class Solution {
private:
int bfs(int src, int parent, const std::unordered_map<int, std::vector<int>>& inverted) {
    std::deque<std::pair<int, int>> myQueue;
    myQueue.push_back({src, 0}); // node, length
    int maxLen = 0;

    while (!myQueue.empty()) {
        auto [node, length] = myQueue.front();
        myQueue.pop_front();

        if (node == parent) {
            continue;
        }

        maxLen = std::max(maxLen, length);

        if (inverted.find(node) != inverted.end()) { // Verifica se o nó existe no mapa
            for (const auto& neighbor : inverted.at(node)) {
                myQueue.push_back({neighbor, length + 1});
            }
        }
    }
    return maxLen;
}
public:
    int maximumInvitations(vector<int>& favorite) {
        //we are guaranteed to have a cycle, find the longest one

        int longestCycle = 0;
        vector<bool> visited(favorite.size());
        vector<std::pair<int,int>> lenght2Cycles;   


        for (int i = 0; i < favorite.size(); i++)
        {
            if (visited[i])
                continue;
            int start = i;
            int curr = i;
            std::unordered_set<int> currSet;
            while (!visited[curr])
            {
                visited[curr] = true;
                currSet.insert(curr);
                curr = favorite[curr];
            }
            int length = currSet.size();
            while (start != curr)
            {
                length--;
                start = favorite[start];
            }
            longestCycle = std::max(longestCycle, length);
            if (length == 2)
            {
                lenght2Cycles.push_back({curr,favorite[curr]});
            }
        }
        std::unordered_map<int, std::vector<int>> inverted;

        for (int dst = 0; dst < favorite.size(); ++dst) {
            int src = favorite[dst];
            inverted[src].push_back(dst);
        }

        int chainSum = 0;

        for (const auto& [n1,n2] : lenght2Cycles)
        {
            chainSum += bfs(n1,n2,inverted) + bfs(n2,n1,inverted) + 2;
        }
        return std::max(chainSum, longestCycle);
        
    }
};