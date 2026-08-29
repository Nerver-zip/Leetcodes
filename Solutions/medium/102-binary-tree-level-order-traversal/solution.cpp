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
private:
    vector<vector<int>> treeLevels;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) return {};

    std::queue<std::pair<TreeNode*,int>> q;
    
    q.push({root,0});
    treeLevels.push_back({});
    int lastLevel = 0;

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;

        if(lastLevel != level){
            treeLevels.push_back({});
            lastLevel = level;
        }

        treeLevels[level].push_back(node->val); 
        
        q.pop();
	
        if (node->left != nullptr)
            q.push({node->left,level + 1}); 

        if (node->right != nullptr)
            q.push({node->right,level + 1});
    }
    return treeLevels;
    }
};