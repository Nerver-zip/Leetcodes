class Solution {
private:

    struct TrieNode {
        TrieNode* children[26];
        bool isEOW;

        TrieNode() {
            isEOW = false;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        } 
    };
    
    TrieNode* root;

    void insert(TrieNode* root, const string& word){
        if(root == nullptr)
            return;

        TrieNode* node = root;

        for (char c : word){
            int i = c - 'a';
            if(!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }

        node->isEOW = true;
    }
public:
    Solution(){
        root = new TrieNode();
    }

    string longestCommonPrefix(vector<string>& strs) {
        
        for (const auto& word : strs)
            this->insert(root, word);

        string gcp;
        TrieNode* node = root;
        
        while (node) {
            int index = 0, count = 0;
            for (int i = 0; i < 26; ++i) {
                if(node->children[i]){
                    ++count;
                    index = i;
                }
            }

            if(count > 1 || node->isEOW)
                break;

            gcp += char(index + 'a');
            node = node->children[index];
        }
        return gcp;
    }
};
