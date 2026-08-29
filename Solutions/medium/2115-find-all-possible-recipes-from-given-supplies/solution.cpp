#define Graph unordered_map<string, vector<string>>
class Solution {
private:
    Graph buildGraph(const vector<string>& recipes, const vector<vector<string>>& ingredients) {
        Graph myGraph;
        for (int i = 0; i < recipes.size(); i++) {
            myGraph[recipes[i]] = ingredients[i];
        }
        return myGraph;
    }

    unordered_set<string> initSupply(const vector<string>& supplies) {
        unordered_set<string> supplySet;
        for (const auto& ingredient : supplies)
            supplySet.insert(ingredient);
        return supplySet;
    }

    bool dfs(Graph& graph, unordered_set<string>& supplySet, unordered_set<string>& visiting, unordered_set<string>& visited, const string& recipe) {
        if (supplySet.find(recipe) != supplySet.end()) {
            return true;
        }
        if (visiting.find(recipe) != visiting.end()) {
            return false; // detected cycle
        }
        if (visited.find(recipe) != visited.end()) {
            return true;
        }

        visiting.insert(recipe);
        for (const auto& ingredient : graph[recipe]) {
            if (supplySet.find(ingredient) == supplySet.end()) {
                if (graph.find(ingredient) == graph.end() || !dfs(graph, supplySet, visiting, visited, ingredient)) {
                    visiting.erase(recipe);
                    return false;
                }
            }
        }
        visiting.erase(recipe);
        visited.insert(recipe);
        supplySet.insert(recipe);
        return true;
    }

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        Graph graph = buildGraph(recipes, ingredients);
        unordered_set<string> supplySet = initSupply(supplies);
        unordered_set<string> visiting;
        unordered_set<string> visited;
        vector<string> canCreate;

        for (const auto& recipe : recipes) {
            if (dfs(graph, supplySet, visiting, visited, recipe)) {
                canCreate.push_back(recipe);
            }
        }
        return canCreate;
    }
};