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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        
        auto solve = [&ans](auto&& self, TreeNode* root)->pair<int,int>{        
            if(!root){
                return {0,0};
            }
            
            auto left = self(self, root->left);
            auto right = self(self, root->right);

            int sum = root->val + left.first + right.first;
            int count = 1 + left.second + right.second;

            if(sum / count == root->val){
                ++ans;
            }

            return {sum, count};
        };

        solve(solve, root);
    
        return ans;
    }
};