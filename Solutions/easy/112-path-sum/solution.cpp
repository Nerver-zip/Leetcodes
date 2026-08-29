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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        bool hasPath = false;
        dfs(root, targetSum, 0, hasPath);
        return hasPath;
    }
private:
    void dfs(TreeNode* root, int targetSum, int curr, bool& hasPath){
        if(root && !root->left && !root->right && curr + root->val == targetSum){
            hasPath = true;
            return;
        }

        if(!hasPath && root){
            dfs(root->left, targetSum, curr + root->val, hasPath);
            dfs(root->right, targetSum, curr + root->val, hasPath);
        }
    }
};