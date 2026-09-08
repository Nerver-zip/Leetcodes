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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        std::queue<std::pair<TreeNode*, int>> nodeQueue;
        int currLevel = -1;

        nodeQueue.push({root,0});

        while (!nodeQueue.empty())
        {
            auto [currNode, nodeLevel] = nodeQueue.front();
            nodeQueue.pop();

            if (nodeLevel > currLevel) 
            {
                ans.push_back(currNode->val);
                currLevel = nodeLevel;          
            }

            if (currNode->right != nullptr)
                nodeQueue.push({currNode->right, nodeLevel + 1});
            if (currNode->left != nullptr)
                nodeQueue.push({currNode->left, nodeLevel + 1});
        }
        return ans;
    }
};