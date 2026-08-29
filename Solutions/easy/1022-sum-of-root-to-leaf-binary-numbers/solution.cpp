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
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
private:
    int ans = 0;
    void dfs(TreeNode* root, int val){
        if(root && !root->left && !root->right){
            ans += (val << 1) | root->val;
            return;
        }
        if(root){
            dfs(root->left, (val << 1) | root->val);
            dfs(root->right, (val << 1) | root->val);
        }
    }
};