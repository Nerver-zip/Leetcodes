class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        sort(nodes.begin(), nodes.end());
        
        TreeNode* newRoot = nullptr;
        auto solve = [&](auto&& self, int l, int r) -> void {
            if(l > r)
                return;
            int mid = (r + l)/2;
            newRoot = insert(newRoot, nodes[mid]);
            self(self, mid+1, r);
            self(self, l, mid-1);
        };

        solve(solve, 0, nodes.size()-1);
        return newRoot;
    }
private:
    vector<int> nodes;

    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            nodes.push_back(root->val);
            dfs(root->right);
        }
    }
    
    TreeNode* insert(TreeNode* root, int val){
        if(!root)
            return new TreeNode(val);
        else if(val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }
};