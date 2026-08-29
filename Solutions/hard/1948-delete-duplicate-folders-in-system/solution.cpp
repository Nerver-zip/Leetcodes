struct TrieNode {
    map<string, TrieNode*> children; 
    vector<string> path;             
    string signature;                
};

class Solution {
private:
    string join(const vector<string>& vec, const string& sep) {
        string result;
        for (const string& s : vec) {
            result += s;
        }
        return result;
    }
public:
    TrieNode* buildTrie(const vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (const auto& path : paths) {
            TrieNode* node = root;
            for (const string& folder : path) {
                if (!node->children.count(folder)) {
                    node->children[folder] = new TrieNode();
                }
                node = node->children[folder];
            }
            node->path = path;
        }
        return root;
    }

    string getSignatures(TrieNode* node, unordered_map<string, vector<TrieNode*>>& sigMap) {
        if (node->children.empty()) {
            node->signature = "()";
            return node->signature;
        }

        vector<string> parts;
        for (const auto& [name, child] : node->children) {
            string childSig = getSignatures(child, sigMap);
            parts.push_back(name + "#" + childSig);
        }

        sort(parts.begin(), parts.end());
        node->signature = "(" + join(parts, "") + ")";
        sigMap[node->signature].push_back(node);
        return node->signature;
    }

    void collectPaths(TrieNode* node, unordered_map<string, vector<TrieNode*>>& sigMap, vector<vector<string>>& result) {
        if (!node->signature.empty() && sigMap[node->signature].size() > 1) {
            return; // Subárvore duplicada
        }

        if (!node->path.empty()) {
            result.push_back(node->path);
        }

        for (auto& [name, child] : node->children) {
            collectPaths(child, sigMap, result);
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = buildTrie(paths);
        unordered_map<string, vector<TrieNode*>> sigMap;

        getSignatures(root, sigMap);

        vector<vector<string>> result;
        collectPaths(root, sigMap, result);
        return result;
    }
};