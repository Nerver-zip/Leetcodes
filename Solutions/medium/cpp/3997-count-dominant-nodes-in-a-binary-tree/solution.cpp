class Solution {
public:
    int countDominantNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }

private:
    int ans = 0;

    int dfs(TreeNode* root, int curr){
        if(root == nullptr){
            return curr;
        }
        
        int mx_left = max(root->val, dfs(root->left, root->val));
        int mx_right = max(root->val, dfs(root->right, root->val));
        
        int mx = max({mx_left, mx_right, root->val});
        if(mx == root->val)
            ++ans;
        
        return mx;
    }
};