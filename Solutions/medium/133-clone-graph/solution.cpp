class Solution {
private:
    std::unordered_map<int,Node*> nodeMap;
private:
    void dfs(Node* node){
        nodeMap[node->val] = new Node(node->val);
        for (const auto& neighbor : node->neighbors)
        {
            if (nodeMap[neighbor->val] == nullptr)
            {
                dfs(neighbor);
            }
            nodeMap[node->val]->neighbors.push_back(nodeMap[neighbor->val]);
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        dfs(node);
        return nodeMap[node->val];
    }
};