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
    vector<int> largestValues(TreeNode* root) {
        
        if (root == nullptr) return {};

        std::queue<std::pair<TreeNode*,int>> q;
        
        int lastLevel = 0;
        vector<int> largestVals;
        vector<int> currLevel;

        q.push({root,lastLevel});

        while (!q.empty())
        {
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level != lastLevel)
            {
                lastLevel = level;
                int max = *std::max_element(currLevel.begin(),currLevel.end());
                largestVals.push_back(max);
                currLevel.clear();
            }
            
            currLevel.push_back(temp->val);

            if (temp->left != nullptr)
            {
                q.push({temp->left,level + 1});
            }
            
            if(temp->right != nullptr){
                q.push({temp->right,level + 1});
            }   
        }
        int max = *std::max_element(currLevel.begin(),currLevel.end());
        largestVals.push_back(max);
        return largestVals;
    }
};
