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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        int maxSum = INT32_MIN, currLevel = 1, ans = 1;

        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(), levelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                auto currNode = q.front();
                q.pop();
                
                levelSum += currNode->val;

                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
            
            if(maxSum < levelSum){
                maxSum = levelSum;
                ans = currLevel;
            }

            ++currLevel;
        }

        return ans;
    }
};