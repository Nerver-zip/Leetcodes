class Solution {
private:
    unordered_map<TreeNode*, std::pair<int,int>> cache;
    std::pair<int,int> dfs(TreeNode* root){
        if(root == nullptr)
        {
            return {0, 0};
        }
        if (cache.find(root) != cache.end())
        {
            return cache[root];
        }
        std::pair<int, int> left = dfs(root->left);
        std::pair<int, int> right = dfs(root->right);

        int rob = root->val + left.second + right.second; //sum with the value of not robbed

        //choose between robbing or not
        int notRob = std::max(left.first, left.second) + std::max(right.first, right.second);
        cache[root] = {rob, notRob};
        return cache[root];
    }
public:
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return std::max(ans.first, ans.second);
    }
};