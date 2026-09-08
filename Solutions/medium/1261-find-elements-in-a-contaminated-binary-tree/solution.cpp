class FindElements {
private: 
    TreeNode* root;
    std::unordered_set<int> values;

    void dfs(TreeNode* root, int newVal){
        if (root != nullptr)
        {
            dfs(root->left,newVal * 2 + 1);
            root->val = newVal;
            values.insert(root->val);
            dfs(root->right,newVal * 2 + 2);
        }
        return;
    }
public:
    FindElements(TreeNode* root) {
        this->root = root;
        dfs(root,0);
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
};