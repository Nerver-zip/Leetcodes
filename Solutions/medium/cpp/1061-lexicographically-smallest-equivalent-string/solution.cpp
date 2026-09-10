class Solution {
private:
    pair<unordered_set<char>, int> bfs(const vector<vector<char>>& graph, vector<bool>& visited, char c){
        queue<char> q;
        unordered_set<char> charSet;
        char smallest = c;
        q.push(c);

        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            charSet.insert(curr);
            visited[curr - 'a'] = true;

            if(curr < smallest)
                smallest = curr;
            
            for (const auto& neigh : graph[curr - 'a'])
            {
                if(!visited[neigh - 'a'])
                    q.push(neigh);
            }
        }
        return {charSet, smallest};
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<char>> graph(26);
        vector<bool> visited(26);

        for (int i = 0; i < s1.size(); ++i)
        {
            graph[s1[i] - 'a'].push_back(s2[i]);
            graph[s2[i] - 'a'].push_back(s1[i]);
        }

        vector<pair<unordered_set<char>, int>> components;
        for (int i = 0; i < 26; ++i)
        {
            if(!visited[i])
                components.push_back(bfs(graph, visited, i + 'a'));
        }
        
        string ans;
        for (char c : baseStr)
            for (const auto& component : components)
                if(component.first.find(c) != component.first.end())
                    ans += component.second;
    
        return ans;
    }
};