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
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* root){
        if(root && ans){
            int leftHeight = height(root->left);
            int rightHeight = height(root->right);
            
            if(abs(leftHeight - rightHeight) > 1)
                ans = false;

            dfs(root->left);
            dfs(root->right);
        }
    }

    int height(TreeNode* root){
        if(!root)
            return 0;

        return max(1 + height(root->left), 1 + height(root->right));
    }
private:
    bool ans = true;
};