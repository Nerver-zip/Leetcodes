/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
constexpr int MOD = 1000000007; 
using ll = long long;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        ll total_sum = sum(root);
        ll ans = 0;

        for (const auto& [_,subtree_sum] : subtree)
            ans = max(ans, (total_sum - subtree_sum) * subtree_sum);
        
        return ans % MOD;
    }

private:
    unordered_map<TreeNode*, ll> subtree;
    ll sum(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        return subtree[root] = root->val + sum(root->left) + sum(root->right);
    }
};