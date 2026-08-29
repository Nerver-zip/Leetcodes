class Solution {
private:
    std::pair<int, TreeNode*> dfs(TreeNode* root){
        if (root == nullptr)
        {
            return {0, nullptr};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first > right.first)
            return {left.first + 1, left.second};
        if (left.first < right.first)
            return {right.first + 1, right.second};
        return {left.first + 1, root};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};