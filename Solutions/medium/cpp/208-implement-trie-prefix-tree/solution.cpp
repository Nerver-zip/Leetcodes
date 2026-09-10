class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        
        for (char c : word) {
            int i = c - 'a';
            if(!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isEOW = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int i = c - 'a';
            if(!node->children[i])
                return false;
            node = node->children[i];
        }
        return node->isEOW;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char c : prefix) {
            int i = c - 'a';
            if(!node->children[i])
                return false;
            node = node->children[i];
        }
        
        queue<TrieNode*> q;
        q.push(node);

        while (!q.empty()) {
            auto currNode = q.front();
            q.pop();

            if(currNode->isEOW)
                return true;

            for (const auto& neigh : currNode->children) {
                if(neigh)
                    q.push(neigh);
            }
        }

        return false;
    }

private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEOW;

        TrieNode(){
            isEOW = false;            
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };

    TrieNode* root;
};